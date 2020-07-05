#Using sorted()
#it's a built-in function in python
#list >> sorted version of that list

#We can do this even more directily
#using the built-in function 'sorted'
#that takes a sequence as a parameter 
#and returns a sorted sequence

d = {'a':10,'b':1,'c':22}
print d.items()
t = sorted(d.items())
print t

#this loop is going to run in key-sorted order.
for k,v in sorted(d.items()):
	print k,v
