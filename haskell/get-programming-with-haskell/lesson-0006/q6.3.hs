-- Q6.3
-- Write a function inFirstHalf that returns True if an element is in the first half of a list, and otherwise returns False


inFirstHalf n aList = elem n list 
    where list = take (div (length aList) 2) aList

-- inFirstHalf val aList = val `elem` firstHalf
--     where midpoint = (length aList) `div` 2
--           firstHalf = take midpoint aList