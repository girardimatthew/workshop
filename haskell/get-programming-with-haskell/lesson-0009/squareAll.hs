-- squareAll

squareAll [] = []
squareAll (x:xs) = x^2:squareAll xs
