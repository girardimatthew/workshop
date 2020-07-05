function p = computeProjection(a)
b = ones(1,length(a));
assert(length(b)==length(a))
p = (dot(a,b)/sum(a.^2)).*a;
%p = (a*b'/sum(a.^2)).*a;
end