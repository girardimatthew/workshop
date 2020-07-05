-- mul3ByAll

mul3ByAll [] = []
mul3ByAll (x:xs) = (3 * x):mul3ByAll xs