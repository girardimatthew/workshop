# Skipping with continue
# 

fhand = open('mbox-short.txt')
for line in fhand:
	line = line.rstrip()				# strip off the white space
	#Skip 'uninteresting lines'
	if not line.startswith('From:'):		#Loop through all of the lines in the file
		continue
	#Process our 'interesting' line
	print line  			
