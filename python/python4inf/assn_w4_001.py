
def computepay(h,r):
	if hrs <= 40:
		pay = hrs*rt
	else:
		pay = 40*rt + (rt*1.5*(hrs-40))
	return pay

try:
	hinp = raw_input('Enter Hours:')
	hrs = float(hinp)
	rinp = raw_input('Enter Rate:')
	rt = float(rinp)
except:
	print 'Error, please enter numeric value'
	quit()

p = computepay(hrs,rt)
print p
