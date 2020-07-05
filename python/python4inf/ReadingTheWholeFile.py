fhand = open('mbox-short.txt')
inp = fhand.read()			#Read the whole file (newlines and all) into a single string
print 'Lenght:',len(inp)
print 'From 0 to 20:',inp[:20]

