import Data.Char

toLowerCase :: String -> String
toLowerCase str = map toLower str

cleanString :: String -> String
cleanString str = filter isAlpha str

finalString :: String -> String
finalString = toLowerCase.cleanString

isPalindrome :: String -> Bool
isPalindrome str = s1 == reverse(s1)
  where s1 = finalString str

main :: IO ()
main = do
  putStrLn "Please enter a phrase: "
  userInput <- getLine

  if isPalindrome userInput then
    putStrLn (userInput ++ " is a palindrome!")
  else
    putStrLn (userInput ++ " is NOT a palindrome.")
