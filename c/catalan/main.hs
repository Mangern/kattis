{-# LANGUAGE BlockArguments #-}
{-# LANGUAGE Arrows #-}
import Control.Arrow
import Control.Category
import Control.Monad
import Prelude hiding (id,(.))
 
list_to_string :: [Integer] -> String
list_to_string = unwords . map show

list_to_lines :: [Integer] -> String
list_to_lines [] = ""
list_to_lines (x:xs) = (show x) ++ "\n" ++ (list_to_lines xs)

main :: IO ()
main = do
    input <- getLine
    let n_tests = (read input :: Integer)
    tests <- replicateM (read input :: Integer) getLine
    putStr (list_to_lines tests)
