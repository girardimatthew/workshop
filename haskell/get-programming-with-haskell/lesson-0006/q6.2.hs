-- Q6.2
-- Write a function subseq that takes three arguments: a start position, an end position,
-- and a list. The function should return the subsequence between the start and end.
-- For example:
-- subseq 2 5 [1 .. 10] 
-- [3,4,5]

-- subseq 2 7 "a puppy"
-- "puppy"

mySubseq start end aList = take (end-start) (drop start aList)

-- subseq start end aList = take difference (drop start aList)
--     where difference = end - start