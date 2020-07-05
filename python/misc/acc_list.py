#!/usr/bin/python

list1 = ['physics', 'chemistry', 1997, 2000];
list2 = [1, 2, 3, 4, 5, 6, 7 ];

# access values in lists
print "list1: ", list1
print "list1[0]: ", list1[0]
print "list2: ", list2
print "list2[1:5]: ", list2[1:5]

# update single or multiple elements of lists
print "Value available at index 2 : "
print list1[2]
list1[2] = 2001;
print "New value available at index 2 : "
print list1[2]
print "list1: ", list1

# remove a list element
print list1
del list1[2];
print "After deleting value at index 2 : "
print list1