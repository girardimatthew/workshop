# Tuples are Comparable 
# the comparison operators work with tuples and other sequences
# If the first item is equal 

#(0,1,2) > (5,1,2)
#(0,1,200000) < (0,3,4)
#('Jones','Sally') < ('Jones','Fred')
#('Jones','Sally') > ('Adams','Sam')

#Sorting Lists of Tuples
#We can take advantage of the ability to sort a list of tuples to
#get a sorted version of a dictionary
#First we sort the dictionary by the key using the items()
#method

d = {'a':10,'b':1,'c':22}
t = d.items()
print 'not sorted', t
t.sort()
print 'sort by keys', t
