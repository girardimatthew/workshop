-- myDrop

myDrop :: Integer -> [a] -> [a] 
myDrop _ []     = [] 
myDrop n xs | n < 1 = xs
myDrop n (_:xs) = myDrop (n-1) xs