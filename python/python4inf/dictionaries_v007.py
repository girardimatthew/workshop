#
# Definite loops and Dictionaries 
# Even though dictionaries are not stored in order 
# we can write a for loop that goes through all the entries in a dictionary -
# actually it goes through all of the keys in the dictionary 
# and look up the values 
# 

counts = {'chuck':1,'fred':42,'jan':100}
for key in counts:
	print key, counts[key]



