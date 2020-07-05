% single line solution

function I = divvy02(I,k)
    I(mod(I,k) ~= 0) = I(mod(I,k) ~= 0) * k;
end
% same solution as above, but it repeats the modulo computation