function out = generationXYZ(y)

if y >= 1966 && y <= 2012
    if y >=1966 && y <= 1980
        out = 'X';
    elseif y >= 1981 && y <= 1999
        out = 'Y';
    else
        out = 'Z';
    end
elseif y <= 1965
    out = 'O';
else
    out = 'K';
end