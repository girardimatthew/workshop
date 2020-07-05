#Sort by values instead of key
# > if we could construct a list of tuples 
# of the form (value,key) we could sort by value
# We do this with a for loop 
# that creates a list of tuples 

# We need to create a temporary variable
# 

c = {'a':10,'b':1,'c':22}	# dictionary
tmp = list()			# temporary list
for k,v in c.items():		# loop the item in a non-sorted order
				# using the .append() operation we're 
	tmp.append((v,k))	# going to add a tuple that is value, key
				# we're making the value firt and the key second

print tmp			#sort takes this list. List are mutable 
				#the individual tuples can't be changed
				#but the order of the tuples can be changed 
				#becuase their in a list
			
tmp.sort(reverse=True)		#you sort from the highest down the lowest  
print tmp

#If we want to sort in some other way
#we just construct a list where we put it in the order
#that we want it sorted.
