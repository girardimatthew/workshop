def pH2Category(pH):
    # Computes the category (string) corresponding to the input pH
    # value (number)
     
    if pH < 0 or pH > 14:
        category = "pH out of range"
    elif pH < 3:
       category = "Strongly acidic"
    elif pH < 6:
       category = "Weakly acidic"
    elif pH <= 8:
        category = "Neutral"
    elif pH <= 11:
        category = "Weakly basic"
    else:
        category = "Strongly basic"
    return category