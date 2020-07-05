function [even, odd] = separate_by_two02(A)
    even = A(mod(A,2) == 0)';   % mod gives 0 if even
    odd  = A(mod(A,2) == 1)';   % mod gives 1 if odd
end
% note that this one will not put non-integers in any of the outputs