#To choose an element from a sequence at random, you can use choice:

import random 

t = [1,2,3,4,5]
print t
for i in range(10):
	x = random.choice(t)
	print x
