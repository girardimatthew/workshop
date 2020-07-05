import numpy as np
 
def removeIncomplete(id):
    # Indices of id-numbers that will be retained
    completeIds = np.ones(np.size(id), dtype=bool)
 
    # Loop over all id-numbers
    for i in range(np.size(id)):
        # Current experiment-number
        experimentNumber = np.floor(id[i])
     
        # Count number of parts with current experiment-number
        numberOfParts = np.sum(np.floor(id) == experimentNumber)
 
        # Mark id-number as incomplete if there are not 3 parts
        if numberOfParts != 3:
            completeIds[i] = False
 
    # Remove incomplete id-numbers
    idComplete = id[completeIds]
 
    # Insert your code here
    return idComplete