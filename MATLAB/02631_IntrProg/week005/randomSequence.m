function r = randomSequence(mu, R, N)
% return a sequence of N random numbers on the range 
% [mu - R/2, mu + R/2]
% INPUT
%   mu  : Mean of distribution (scalar decimal number) 
%   R   : Range of distribution (scalar decimal number) 
%   N   : Number of random draws (integer)
% OUTPUT
%   r   : Random numbers (vector of decimal numbers)
A = mu - (R/2);
B = mu + (R/2);
r = unifrnd(A,B,1,N);
end
