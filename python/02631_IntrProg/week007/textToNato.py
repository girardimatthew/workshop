import numpy as np
 
def textToNato(plainText):
 
    # Define the NATO alphabet code words
    NatoCode = np.array(["Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
                     "Juliet", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                 "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"])
 
    # Define the corresponding normal alphabet
    Alphabet = np.array([
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N",
        "O","P","Q","R","S","T","U","V","W","X","Y","Z"])
 
    # Create initial empty natoText
    natoText = ""
 
    # Loop over the letters in the input text
    for k in range(len(plainText)):
        # Current letter
        Letter = plainText[k].upper()
     
        # Find the corresponding NATO code
        code = NatoCode[Letter == Alphabet]
 
        # Put code at the end of natoText
        natoText += code[0]
 
        # Put in a dash, if this is not the last letter
        if (k != len(plainText)-1):
            natoText += "-"
 
    return natoText