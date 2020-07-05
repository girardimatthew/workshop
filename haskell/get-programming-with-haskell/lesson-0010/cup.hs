cup f10z = \message -> message f10z
getOz aCup = aCup (\f10z -> f10z)

drink aCup ozDrank = if ozDiff >= 0
                     then cup ozDiff
                     else cup 0
    where f10z = getOz aCup 
          ozDiff = f10z - ozDrank

isEmpty aCup = getOz aCup == 0

-- afterManySips = foldl drink coffeCup [1,1,1,1,1]