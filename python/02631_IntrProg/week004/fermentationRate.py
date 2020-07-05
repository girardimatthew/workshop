import numpy as np
 
def fermentationRate(measuredRate, lowerBound, upperBound):
# Returns average of elements of vector measuredRate greater than
# lowerBound and less than upperBound
    goodRates = (measuredRate > lowerBound) & (measuredRate < upperBound)
    averageRate = np.mean(measuredRate[goodRates])
    return averageRate