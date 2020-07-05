-- sumOfSquares

sumOfSquares xs = foldl (+) 0 (map (^2) xs)