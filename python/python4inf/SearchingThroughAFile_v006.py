# Prompt for File Name

fname = raw_input('Enter the file name: ')
try:
	fhand = open(fname)
	count = 0
	for line in fhand:
		if line.startswith('Subject:'):
			count = count + 1
	print 'There were',count,'subject lines in ',fname
except:
	print 'No such file.'
	exit()
