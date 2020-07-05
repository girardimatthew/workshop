function coinsToReturn = coinReturn(coinsInMachine, amount)
%coinReturn
%   this function takes as input vector containing the values of 
%   coins available in the machine (ordered starting with the smallest value) 
%   as well as the amount to be paid out. The function must return a 
%   vector with the values of the coins that are paid out 
%   (in the order defined by the algorithm).
%   
%   USAGE:
%   coinsToReturn = coinReturn(coinsInMachine, amount)
%
%   INPUT
%   - coinsInMachine:       The values of the kinds of coins available in the machine (vector)
%   - amount:               Amount to be paid out (decimal number)
%
%   OUTPUT
%   - coinsToReturn:        The values of the coins that are paid out (vector).
%
x = amount;
coinsToReturn = [];
while (x >= min(coinsInMachine)/2)
    cIdx = max(find(coinsInMachine <= x));
    cVal = coinsInMachine(cIdx);
    coinsToReturn = [coinsToReturn, cVal];
    x = x - cVal;
end
end