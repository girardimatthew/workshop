function [even,odd] = separate_by_two(A)
    even = A(fix(A/2) == A/2)';  % if A is even, rounding does not do anything to A/2
    odd  = A(fix(A/2) ~= A/2)';  % if A is odd, it gets rid of the .5 part, so they won't be equal
end
% note that this will put non-integers into odd