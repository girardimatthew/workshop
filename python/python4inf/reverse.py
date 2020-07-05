# Write a while loop that starts at the last 
# character in the string and works its way 
# backwards to the first character in the string, 
# printing each letter on a separate line, except backwards.

ipt = raw_input('Please, enter a word, or a statement: ')
str = str(ipt)
#print type(str)
#print len(str)
index = len(str) - 1
#print index
i = len(str)
#print i
strlist  = []
for i in range(len(str)):
	strlist.append(0)
#print len(strlist)
count = 0
while i >= 0:
	strlist[count] = str[index]
	i = i - 1
	index = index - 1
	count = count + 1
print strlist
