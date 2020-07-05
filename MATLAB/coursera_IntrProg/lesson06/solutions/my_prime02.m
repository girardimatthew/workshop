% with no explicit loops

function prim = my_prime02(p)
    v = 2:sqrt(p);
    v = v(rem(p,v) == 0);           % if p is prime, none of the remainders can be 0
    prim = ~length(v) && (p ~= 1);  % so if v has any elements, p is not prime
end                                 % 1 is handled by the (p ~= 1) condition