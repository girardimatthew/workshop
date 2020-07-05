#Even shorter Version of tuples_v006.py
#it's really dense

c = {'a':10,'b':1,'c':22}                  #Dictionary
print sorted([(v,k) for k,v in c.items()]) #List comprehension
#it is a python syntax and says contruct dynamically a list of tuples v,k 
#loop through the items with k and v taking on the successive values.

#Tuples are like lists except you can't change it
