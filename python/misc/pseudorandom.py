#!/usr/bin/env python
# Python: Random numbers

import random

# pseudo-random numbers
def print_rand():
	print "PSEUDO-RANDOM NUMBERS"
	print "UPPER BOUND:", 1
	print "LOWER BOUND:", 0
	for i in range(10):
		x = random.random()
		print i, ">", x

# upper bound only
def upper_rand():
	upper = 3
	print "##########################################"
	print "PSEUDO-RANDOM NUMBERS"
	print "UPPER BOUND:", upper
	print "LOWER BOUND:", 0
	for i in range(10):
		x = random.random()
		x = x * upper 
		print i, ">", x

# upper and lower bound
def frand():
	lower = 2
	upper = 6	
	print "##########################################"
	print "PSEUDO-RANDOM NUMBERS"
	print "UPPER BOUND:", upper + lower 
	print "LOWER BOUND:", lower
	for i in range(10):
		x = random.random()
		x = (x * upper) + lower
		print i, ">", x

# random integer
def irand():
	lower = 2
	upper = 7
	print "##########################################"
	print "PSEUDO-RANDOM NUMBERS > INTEGER"
	print "UPPER BOUND:", upper + (lower-1)
	print "LOWER BOUND:", lower
	for i in range(10):
		x = random.random()
		x = int((x * upper) + lower )
		print i, ">", x

def main():
	print_rand()
	upper_rand()
	frand()
	irand()

if __name__ == '__main__':
	main()
	
