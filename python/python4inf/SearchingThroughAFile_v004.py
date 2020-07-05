# Using in to select lines 

fhand = open('mbox-short.txt')
for line in fhand:
	line = line.rstrip()				# strip off the white space
	if not '@uct.ac.za' in line:			# look for lines that have @uct.ac.za in them 
		continue
	print line  			
