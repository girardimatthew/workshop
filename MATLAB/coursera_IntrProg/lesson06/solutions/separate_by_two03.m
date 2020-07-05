% using mod (or rem)

function [even,odd] = separate_by_two03(A)
    mod2 = logical(mod(A,2));
    even = A(~mod2)';       % modulo 2 is zero for even numbers (logical false), so we need to negate it
    odd  = A(mod2)';        % modulo 2 is non-zero for odd numbers, that is, logical true
end
% note that this will put non-integers into odd