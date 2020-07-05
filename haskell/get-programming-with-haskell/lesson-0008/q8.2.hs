-- Q8.2 Calculating Fibonacci numbers is perhaps the single most common example of a
-- recursive function. The most straightforward definition is as follows:
--  fib 0 = 0
--  fib 1 = 1
--  fib n = fib (n-1) + fib (n-2)
-- Like the Ackermann function, this implementation quickly explodes due to the mutu- ally recursive calls. But unlike the Ackermann function, there’s a much more efficient way to compute the nth Fibonacci number. Write a function, fastFib, that can compute the 1,000th Fibonacci number nearly instantly. Hint: fastFib takes three arguments: n1, n2, and counter. To calculate the 1,000th Fibonacci number, you call fastFib 1 1 1000 and for the 5th, you call fastFib 1 1 5.

myFibonacci 0 = 0 
myFibonacci 1 = 1
myFibonacci n = myFibonacci (n-1) + myFibonacci (n-2)

fastFib _ _ 0 = 0
fastFib _ _ 1 = 1
fastFib _ _ 2 = 2
fastFib x y 3 = x + y
fastFib x y c = fastFib (x + y) x (c - 1)
fib n = fastFib 1 1 n