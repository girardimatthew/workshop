import numpy as np
 
def letterFrequency(filename):
    # Computes the frequency of each letter, a to z, case insensitive
    # in the text file (filename given as input)
 
    # Define alphabet
    alphabet = "abcdefghijklmnopqrstuvwxyz"
 
    # Read file into string
    filein = open(filename, "r")
    lines = filein.readlines()
    text = "".join(lines)
 
    # Convert to lower case
    text = text.lower()
 
    # Compute number of occurencies
    occur = np.zeros(26)
    for i in range(26):
        occur[i] = text.count(alphabet[i])
 
    # Compute frequencies in percent
    freq = occur / np.sum(occur) * 100
    return freq