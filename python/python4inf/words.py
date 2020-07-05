#Get the name of the file and open it
name = raw_input('Enter file:')
handle = open(name, 'r')
text = handle.read()
words = text.split()

#Count words frequency
counts = dict()
for word in words: 
   counts[word] = counts.get(word,0) + 1

#Find teh most common word
bigcount = None
bigword = None
for word,count in counts.items():
    if bigcount == None or count > bigcount:
        bigword = word 
        bigcount = count 

#All done
print bigword, bigcount
