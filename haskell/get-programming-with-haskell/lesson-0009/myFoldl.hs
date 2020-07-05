-- myFoldl

myFoldl f init [] = init
myFoldl f init (x:xs) = myFoldl f newInit xs
   where newInit = f init x