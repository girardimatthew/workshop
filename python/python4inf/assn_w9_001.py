# 9.4 Write a program to read through the mbox-short.txt and figure out 
# who has the sent the greatest number of mail messages. 
# The program looks for 'From ' lines and takes the second word of those 
# lines as the person who sent the mail. The program creates a Python 
# dictionary that maps the sender's mail address to a count of 
# the number of times they appear in the file. After the dictionary is produced, 
# the program reads through the dictionary using a maximum loop to find the most prolific committer.

finp = raw_input('Enter a file: ')
if len(finp) < 1 : finp = "mbox-short.txt"
fname = open(finp, 'r')
maildict = dict()
lst = list()
for line in fname:
	if not line.startswith('From '):
		continue
	lst = line.rstrip().split()
	#print lst[1]
	maildict[lst[1]] = maildict.get(lst[1],0) + 1
	#if lst[1] not in maildict:
	#	maildict[lst[1]] = 1
	#else:
	#	maildict[lst[1]] += 1
#print maildict
bigcount = None
bigword = None
for mail,count in maildict.items():
	if bigcount is None or count > bigcount:
		bigword = mail
		bigcount = count
print bigword, bigcount
