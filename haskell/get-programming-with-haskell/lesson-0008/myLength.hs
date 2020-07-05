-- myLength

-- myLength [] = 0
-- myLength xs = 1 + myLength (tail xs)

myLength [] = 0
myLength (x:xs) = 1 + myLength xs
