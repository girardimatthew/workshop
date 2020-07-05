# Tuples are like lists
# Tuples are another kind of sequence that function much like 
# a list - they have elements which are indexed starting at 0
# they are a non-changeable list. like lists but we use parentheses ()
# Tuples are "immutable", you can not alter its contents

# l = list()
# dir(l)

# t = tuple()
# dir(t)

# Tuples are much more efficient

d = dict()
d['csev'] = 2
d['cwen'] = 4
for (k,v) in d.items():
	print k,v
# it is a list but each things inside the list is a tuple 

tups = d.items()
print tups #get a lists of two tuples. 
