-- calcChange
calcChange owed given = if change > 0 
                        then change
                        else 0
    where change = given - owed

main = do
    print "function calcChange"
    print (calcChange 10 15)
    
    