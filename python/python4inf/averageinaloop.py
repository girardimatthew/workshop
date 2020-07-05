sum = 0
count = 0
print 'Before', sum, count
for value in [9,41,12,3,74,15]:
	sum = sum + value
	count = count + 1
	print count, sum, value
print 'After', sum, count, sum/count
