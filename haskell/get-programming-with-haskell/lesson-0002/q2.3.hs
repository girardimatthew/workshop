-- Q2.3 Write a function that takes a value n. If n is even, the function returns n - 2, and if the number is odd, the function returns 3 × n + 1. To check whether the number is even, you can use either Haskell’s even function or mod (Haskell’s modulo function).

ifEvenOtherwise n = if even
                    then nMinusTwo
                    else threeTimesNplusOne
    where even = mod n 2 == 0
          nMinusTwo = n - 2
          threeTimesNplusOne = 3 * n + 1

main = do
    print "Execise Q2.3"
    let x = 3
    print (x)
    print (ifEvenOtherwise x)
    let x = 4
    print (x)
    print (ifEvenOtherwise x)