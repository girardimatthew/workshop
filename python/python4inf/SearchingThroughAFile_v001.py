# Print lines starting with 'From:'
# Problem: How do we remove the newline character?

fhand = open('mbox-short.txt')
for line in fhand:
	if line.startswith('From:'):		#Loop through all of the lines in the file
		print line			
