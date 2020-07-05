# Write a program that repeatedly prompts a user for integer numbers until the user enters 'done'. 
# Once 'done' is entered, print out the largest and smallest of the numbers. 
# If the user enters anything other than a valid number catch it with a try/except 
# and put out an appropriate message and ignore the number. 
# Enter the numbers from the book for problem 5.1 and Match the desired output as shown.

min = None
max = None
num = 0 

while True:
	inp = raw_input('Enter a number: ')
	if inp == 'done':
		break
	try:
		num = int(inp)
	except:
		print 'Invalid input'
		continue
	
	if min is None or num < min:
		min = num
	elif max is None or num > max:
		max = num	

print 'Maximum is', max
print 'Minimum is', min
