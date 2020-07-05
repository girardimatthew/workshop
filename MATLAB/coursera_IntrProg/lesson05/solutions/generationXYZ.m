function gen = generationXYZ(year)
    if year < 1966
        gen = 'O';
    elseif year < 1981
        gen = 'X';
    elseif year < 2000
        gen = 'Y';
    elseif year < 2013
        gen = 'Z';
    else
        gen = 'K';
    end
end