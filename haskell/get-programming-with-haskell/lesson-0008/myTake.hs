-- myTake

-- myTake :: (Num i, Ord i) => i -> [a] -> [a] 
-- myTake n _  
--      | n <= 0   = []  
-- myTake _ []     = [] 
-- myTake n (x:xs) = x : myTake (n-1) xs 


-- 8.2.2 Implementing take
myTake _ [] = []
myTake 0 _ = []
myTake n (x:xs) = x : rest 
    where rest = myTake (n - 1) xs