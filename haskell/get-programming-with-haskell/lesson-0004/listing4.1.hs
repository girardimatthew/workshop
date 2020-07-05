-- ifEvenInc, ifEvenDouble and ifEvenSquare

-- ifEvenInc n = if even n
--               then n + 1
--               else n

-- ifEvenDouble n = if even n
--                 then n * 2
--                 else n

-- ifEvenSquare n = if even n 
--                  then n^2
--                  else n

ifEven myFunction x = if even x
                      then myFunction x 
                      else x

inc n = n+1
double n = n*2
square n = n^2
cube n = n^3

ifEvenInc n = ifEven inc n
ifEvenDouble n = ifEven double n
ifEvenSquare n = ifEven square n
ifEvenCude n = ifEven cube n

main = do 
    print "CiccioBurger"
