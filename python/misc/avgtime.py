#!/usr/bin/python -tt

def main():
	km = 10.0
	ratio = 0.621371
	miles = km*ratio

	m = 43.0
	sec = 30.0
	milli = 0.0
	print "You ran %d km in %d minutes, %d seconds." % (km, m, sec)

	totsec = m*60.0 + sec
	avg = totsec/km
	avgM = avg/60.0
	iMin = int(avgM)
	rSec = (avgM - iMin)*60
	print "Average time per km: %d minutes, %d seconds" % (iMin, rSec) 

if __name__ == '__main__':
	main()