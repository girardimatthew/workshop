-- Q7.1 Tha tail function in Haskell returns an error when called on an empty list. Modify myTail so that it handles the case of an empty list by returning the empty list


myTail2 (_:xs) = xs
myTail2 [] = []