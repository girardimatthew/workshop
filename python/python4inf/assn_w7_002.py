# 7.1 Write a program that prompts for a file name, 
# then opens that file and reads through the file, 
# and print the contents of the file in upper case. 
# Use the file words.txt to produce the output below.
# You can download the sample data at http://www.pythonlearn.com/code/words.txt

#VERSION 2

fname = raw_input('Enter file name: ')
if len(fname) == 0:
	fname = 'words.txt'
fhand = open(fname)
for line in fhand:
	line = line.rstrip().upper()
	#line = line.upper()
	print line
