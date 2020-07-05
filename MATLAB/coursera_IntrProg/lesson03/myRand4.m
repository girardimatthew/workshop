function [a,s] = myRand4(low,high)
a = low + rand(3,4) * (high-low);
s = sumAllElements(a);

function summa = sumAllElements(M)
global v; 
% global variables can cause errors that are very difficult to diagnose
v = M(:);
summa = sum(v);