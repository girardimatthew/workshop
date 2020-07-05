-- §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
-- Q3.2 
-- §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
--
-- Using a let expression and a lambda function aren’t exactly the same thing under the hood. For example, the following code will cause an error if you try to run it:
--  counter x = let x = x + 1
--              in
--                 let x = x + 1 
--                 in
--                     x
-- To prove that let and lambda aren’t identical, rewrite the counter function exactly as it is here, but use nested lambdas instead of let.
-- (Hint: Start at the end.)

-- x = 4
-- counter x = let x = x + 1
--             in 
--                 let x = x + 1
--                 in 
--                     x

counter x = (\x -> 
    (\x -> x) x + 1
    ) x + 1

main = do 
    let x = 1
    print (counter x)
    let x = 2
    print (counter x)
    let x = 3
    print (counter x)
