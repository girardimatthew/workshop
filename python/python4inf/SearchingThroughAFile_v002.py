fhand = open('mbox-short.txt')
for line in fhand:
	line = line.rstrip()			#rstrip say pull white space, and the newlines are alse counted as white space
	if line.startswith('From:'):		#Loop through all of the lines in the file
		print line			
