-- Q7.2 Rewrite myGCD by using pattern matching

myGCDv2 a 0 = a
myGCDv2 a b = myGCDv2 b (a `mod` b)