-- listing 6.3
respond phrase = if '!' `elem` phrase
                 then "wow!"
                 else "uh.. okay"