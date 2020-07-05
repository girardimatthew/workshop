# Write a program which prompts the user for a Celsius temperature, convert the temperature to Fahrenheit and print out the converted temperature.

try:
	fahr_inp = raw_input('Please, Enter Fahrenheit Temperature: ')
	fahr = float(fahr_inp)	
	print fahr,'F'
	celsius = ((fahr -32) / (9.0/5.0))
	print celsius,'C'
except:
	print('Error, please enter numeric value')
	quit()
