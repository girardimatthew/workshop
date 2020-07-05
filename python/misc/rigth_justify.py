#!/usr/bin/python

# Write a function named right_justify that takes a string named s as a parameter and prints the
# string with enough leading spaces so that the last letter of the string is in column 70 of the display.

import math

def right_justify( str ):
	l = len(s)
	space = ' ' * (70 - l)
	print space+str
	return;

s = 'ciccio'
right_justify(s)
