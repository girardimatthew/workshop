-- Q9.2 Your isPalindrome function from lesson 6 doesn’t handle sentences with spaces or capitals. 
-- Use map and filter to make sure the phrase “A man a plan a canal Panama” is recognized as a palindrome.
import Data.Char

isPalindrome text = processedText == reverse processedText 
    where noSpaces = filter (/= ' ') text
          processedText = map toLower noSpaces

-- isPalindrome text = processedText == reverse processedText
--     where processedText = filter (/= ' ') (map toLower text)