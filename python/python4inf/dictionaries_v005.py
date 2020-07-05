# 
# The get method for dictionary
# 
# This pattern of checking to see if a key
# is already in a dictionary and assuming 
# a defualt value if the key is not there is 
# so common, that there is a method called get() 
# that does this for us
# 
# Simplified counting with get()
# We can use get() and provide a default value of zero 
# when the key is not yet in the dictionary - and 
# then just add one 
# 

counts = dict()
names = ['ciccio','salciccio','ciccio','canada','hamilton','canada','salciccio']
print names 
for i in names:
	counts[i] = counts.get(i,0) + 1 
print counts 
