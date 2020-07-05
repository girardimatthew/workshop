-- Q5.1 Now that you know about partial application, you no longer need to use genIfEvenX. Redefine ifEvenInc, ifEvenDouble, and ifEvenSquare by using ifEven and partial application.

inc n = n+1
double n = n*2
square n = n^2
cube n = n^3

ifEven myFunction x = if even x
                      then myFunction x 
                      else x

ifEvenInc = ifEven inc
ifEvenDouble = ifEven double
ifEvenSquare = ifEven square
ifEvenCube = ifEven cube

-- Q5.2 Even if Haskell didn’t have partial application, you could hack together some approximations. Following a similar pattern to flipBinaryArgs (figure 5.6), write a function binaryPartialApplication that takes a binary function and one argument and returns a new function waiting for the missing argument.

binaryPartialApplication binaryFunc arg = (\missingArg -> 
    binaryFunc arg missingArg)
-- takeFromFour = binaryPartialApplication (-) 4