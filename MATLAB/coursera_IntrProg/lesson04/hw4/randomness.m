function matrix = randomness(limit,n,m)
matrix = fix(1 + rand(n,m)*(limit));
end