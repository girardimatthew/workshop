#Using sorted()
#it's a built-in function in python
#list >> sorted version of that list

d = {'a':10,'b':1,'c':22}
print d.items()
t = sorted(d.items())
print t

#this loop is going to run in key-sorted order.
for k,v in sorted(d.items()):
	print k,v
