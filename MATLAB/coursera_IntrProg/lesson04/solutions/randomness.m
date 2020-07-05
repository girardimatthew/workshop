function r = randomness(limit,n,m)
    r = fix(limit * rand(n,m) + 1);
end