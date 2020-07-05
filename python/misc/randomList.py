#!/usr/bin/env python

import random

def randomList(n):
	s = [0] * n
	for i in range(n):
		s[i] = random.random()
	return s

def main():
	 print randomList(8)

if __name__ == '__main__':
	main()
	