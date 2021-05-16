{-# LANGUAGE FlexibleInstances, GeneralizedNewtypeDeriving #-}

module Builder (Builder, mkBuilder, runBuilder) where

import Prelude hiding (id, (.))
import Control.Arrow
import Control.Category

newtype BuilderA m a b = BuilderA { unBuilderA :: Kleisli m a b } deriving (Category, Arrow)

instance Monad m => Semigroup (BuilderA m a a) where (<>) = (>>>)
instance Monad m => Monoid    (BuilderA m a a) where mempty = id

type Builder m = BuilderA m String String
mkBuilder = BuilderA . Kleisli
runBuilder = runKleisli . unBuilderA

