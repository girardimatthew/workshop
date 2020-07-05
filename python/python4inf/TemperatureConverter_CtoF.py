# Write a program which prompts the user for a Celsius temperature, convert the temperature to Fahrenheit and print out the converted temperature.

try:
	celsiusinp = raw_input('Please, Enter Celsius Temperature: ')
	c = float(celsiusinp)	
	print c,'C'
	fahrenheit = (c * (9.0/5.0) + 32)
	print fahrenheit,'F'
except:
	print('Error, please enter numeric value')
	quit()
