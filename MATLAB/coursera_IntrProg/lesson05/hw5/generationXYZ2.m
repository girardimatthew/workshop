function out = generationXYZ2(y)
if y <= 1965
    out = 'O';
elseif y >= 1966 && y <= 2012
    if y >=1966 && y <= 1980
        out = 'X';
    elseif y >= 1981 && y <= 1999
        out = 'Y';
    else
        out = 'Z';
    end
else
    out = 'K';
end