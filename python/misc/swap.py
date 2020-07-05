#!/usr/bin/env python
# Python swap example

def swap(x, y):
	return y, x

def main():
	a = 5
	b = 8
	print "a: %d, b: %d" % (a, b)
	a, b = swap(a, b)
	print "a: %d, b: %d" % (a, b)

if __name__ == '__main__':
	main()
	
