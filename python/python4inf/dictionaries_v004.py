# 
# When we encounter a new name, we need to add a new entry in the
# dictionary and if this the second or later time we have seen the name,
# we simply add one to the count in the dictionary under the name 

counts = dict()
names = ['ciccio','salciccio','ciccio','canada','hamilton','canada','salciccio']
for name in names:
	if name not in counts:
		counts[name] = 1
	else: 
		counts[name] += 1
print counts 
