module Builders (uppercaseB, lowercaseB, reverseB, randomcaseB, appendB, prependB, repeatB) where

import Control.Arrow
import Control.Monad.IO.Class
import Data.Bool
import Data.Char
import System.Random

import Builder

uppercaseB, lowercaseB, reverseB :: (Monad m) => Builder m
uppercaseB = arr $ map toUpper
lowercaseB = arr $ map toLower
reverseB   = arr reverse

randomcaseB :: MonadIO m => Builder m
randomcaseB = mkBuilder $ sequence . map (flap (bool toUpper toLower <$> liftIO randomIO))

appendB, prependB :: Monad m => String -> Builder m
appendB  p = arr (++ p)
prependB p = arr (p ++)

repeatB :: Monad m => Int -> Builder m
repeatB n = arr $ concat . replicate n

flap ff a = ($ a) <$> ff

