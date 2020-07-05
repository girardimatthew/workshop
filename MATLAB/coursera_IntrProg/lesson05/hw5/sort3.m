function out = sort3(a,b,c)
if a >= b
    if b >= c 
        out = [c,b,a]; 
    elseif b <= c && a >=c
        out = [b,c,a];
    else
        out = [b,a,c];
    end
elseif a <= b
    if b >= c && a <= c
        out = [a,c,b];
    elseif b <= c
        out = [a,b,c];
    else
        out = [c,a,b];
    end
end