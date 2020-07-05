--lexical scope

x = 4
add1 y = y + x
add2 y = (\x -> y + x) 3
add3 y = (\y ->
    (\x -> y + x) 1 ) 2

main = do 
    let x = 5
    print (add1 x)
    print (add2 x)
    print (add3 x)