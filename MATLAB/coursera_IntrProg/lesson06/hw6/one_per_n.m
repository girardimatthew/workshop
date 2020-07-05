% slower than one_per_n02
function out = one_per_n(x)
c = 1;
n = 1;
out = [];
for ii = 2:1e5
    if c > 1e4
       out = -1;
    elseif n >= x
        out = c;
        break;
    end
   n =  n + 1/ii;
   c = 1 + c;
end
end