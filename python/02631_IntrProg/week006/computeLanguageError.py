import numpy as np
import pandas as pd
 
def computeLanguageError(freq):
    # Computes the squared error between the letter frequencies given
    # as input and the letter frequencies of 15 languages stored in the
    # file letter_frequencies.csv
 
    # Open the file letter_frequencies.
    data = pd.read_csv("letter_frequencies.csv")
 
    # Extract a matrix containing the letter frequencies for the 15
    # languages and transpose it to yield a size 15 x 26 matrix
    languageFrequencies = np.array(data.iloc[0:26, 1:16]).T
 
    # Compute the squared errors. Subtracting a vector from a matrix will
    # "recycle" the vector, so it is subtracted from each row.
    E = np.sum((languageFrequencies - freq)**2, axis=1)
    return E