
in_range :: Integer -> Integer -> Integer -> Bool
in_range min max x =
x >= min && x <= max

main :: IO ()
  main = do 
  let result::Bool
  result = in_range 3 5 0
  print $ show result

