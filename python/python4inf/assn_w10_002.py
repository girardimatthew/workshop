# 10.2 Write a program to read through the mbox-short.txt 
# and figure out the distribution by hour of the day for 
# each of the messages. You can pull the hour out from the 
# 'From ' line by finding the time and then splitting 
# the string a second time using a colon.
# From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008
# Once you have accumulated the counts for each hour, 
# print out the counts, sorted by hour as shown below. 
# Note that the autograder does not have support for the sorted() function.

name = raw_input('Enter a file: ')
fhand = open(name)
counts = dict()
for line in fhand:
	words = line.split()
	for word in words:
		wrd = word.lower()
		counts[wrd] = counts.get(wrd, 0) + 1

#print counts.items()

flipped = list()
for key, val in counts.items():
	newtup =(val, key)
	#print newtup
	flipped.append(newtup)

#print flipped
flipped.sort(reverse=True)
#print flipped[:5] 

for key, val in flipped[:5]:
	print key, val
