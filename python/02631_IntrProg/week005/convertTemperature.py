def convertTemperature(T, unitFrom, unitTo):
    # Converts a temperature T between units of meaurement Fahrenheit,
    # Celsius and Kelvin.
    # Inputs
    #    T         : Input temperature
    #    unitFrom  : Unit to convert from
    #    unitTo    : Unit to convert to
    # Units can be either of the strings "Fahrenheit", "Celsius", or
    # "Kelvin".
 
    # The function is implemented by always converting to Kelvin and
    # then converting to the desired unit.
 
    # First, convert from unitFrom to Kelvin
    if(unitFrom == "Celsius"):
        K = T + 273.15
    elif(unitFrom == "Fahrenheit"):
        K = (T + 459.67) / 1.8
    else:
        K = T
 
    # Next, convert from Kelvin to unitTo
    if (unitTo == "Celsius"):
        T = K - 273.15
    elif(unitTo == "Fahrenheit"):
        T = 1.8 * K - 459.67
    else:
        T = K
 
    return T