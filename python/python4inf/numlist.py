#!/usr/bin/python
# vim: set fileencoding= utf-8 :

# Write a program which reads a list of numbers until “done" is entered. 
# Once “done” is entered, print out the total, count and average of the numbers.
# If the user enter anything other than a number, print an error message 
# and skip to the next number

total = 0
count = 0
while True:
	inp = raw_input('Enter a number: ')
	
	# Handle the edge cases
	if inp == 'done':
		break
	if len(inp) < 1:	# Check for empty line
		break
	
	# Do the work
	try:
		fnum = float(inp)	
	except:
		print 'Invalid input'
		continue	
	count = count + 1	# Count the valid data
	total = total + fnum
	print fnum, total, count


print 'Average: ', total/count
