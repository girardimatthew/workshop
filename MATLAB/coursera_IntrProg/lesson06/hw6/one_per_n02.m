% much faster than one_per_n
function out = one_per_n02(x)
total=0;
n = 1;
while total < x
    total = (total+1/n); 
    n = n+1;
end
if n-1 > 10000
    out = -1;
else
    out = (n-1);
end