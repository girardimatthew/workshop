-- Ackermann function

ackermann 0 n = n + 1
ackermann m 0 = ackermann (m-1) 1
ackermann m n = ackermann (m-1) (ackermann m (n-1))

-- Because your recursive call is making nested calls to itself, its runtime cost quickly starts to explode! Even though you followed the rules for recursion, you end up getting into serious trouble with the Ackermann function.