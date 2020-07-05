function out = classify(x)
[r, c] = size(x);
if r == 0 || c == 0
    out = -1;
elseif sum(size(x)) == 2
    out = 0;
elseif r == 1 || c == 1
    out = 1;
else
    out = 2;
end