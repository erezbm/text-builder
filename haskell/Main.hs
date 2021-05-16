-- stack script --resolver lts-17.11 --package random --package optparse-applicative
import Control.Monad
import Control.Monad.IO.Class
import Data.Foldable
import Options.Applicative

import Builder
import Builders

main = do
  textBuilder <- execParser opts
  lines <$> getContents >>= traverse_ (runBuilder textBuilder >=> putStrLn)
 where
  opts = info (builderParser <**> helper) mempty

builderParser :: MonadIO m => Parser (Builder m)
builderParser = mconcat <$> many (asum [uppercaseParser, lowercaseParser, reverseParser, randomcaseParser, appendParser, prependParser, repeatParser])
 where
  uppercaseParser  = flag' uppercaseB         (long "uppercase"  <> short 'u' <> help "Uppercase the input")
  lowercaseParser  = flag' lowercaseB         (long "lowercase"  <> short 'l' <> help "Lowercase the input")
  reverseParser    = flag' reverseB           (long "reverse"    <> short 'r' <> help "Reverse the input")
  randomcaseParser = flag' randomcaseB        (long "randomcase" <> short 'R' <> help "Randomcase the input")
  appendParser     = appendB  <$> strOption   (long "append"     <> short 'a' <> help "Append POSTFIX at the end of the input"                <> metavar "POSTFIX")
  prependParser    = prependB <$> strOption   (long "prepend"    <> short 'p' <> help "Prepend PREFIX at the start of the input"              <> metavar "PREFIX")
  repeatParser     = repeatB  <$> option auto (long "repeat"     <> short 'm' <> help "Repeat the input COUNT times (negative COUNT means 0)" <> metavar "COUNT")

