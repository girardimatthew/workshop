#The top 10 most common words
#Simple histogram of the occurrence of words 
#in a file

fhand = open('romeo.txt')					#open a file
counts = dict()							#create a empty counts dictionary
for line in fhand:						#read each line, split each line into words based on spaces 
	words = line.split()					#using the .split()
	for word in words:					#loop through each words
		counts[word] = counts.get(word,0) + 1		#creates new entries and updates old entries

lst = list()							#new list
for key, val in counts.items():					#go trough the dictionary
	lst.append((val,key))					#create the temporary list of tuples 
								#that are val, key
lst.sort(reverse=True)						#
for val, key in lst[:10]:		#it is the first 10 items
	print key, val
