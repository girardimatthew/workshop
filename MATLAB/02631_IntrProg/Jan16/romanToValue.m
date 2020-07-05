function value = romanToValue(roman)
%romanToValue
%   this function takes a roman numeral (string) as input and computes its value. 
%   The function must use the following algorithm:
%       1. Convert each symbol into the value it represents.
%       2. Keep a running total, and a record of the maximum symbol value 
%       encountered so far (both initialized to zero). Run through the 
%       symbols one by one starting from the right:
%           ? If the symbol value is greater than or equal to the maximum, add it to the running total and update the maximum.
%           ? If the symbol value is less than the maximum, subtract it from the running total.
%
%   USAGE:
%   function value = romanToValue(roman)
%
%   INPUT
%   - roman:                Roman numeral (string)
%
%   OUTPUT
%   - value:                Numeric value of the roman numeral (whole number)
%

symbol = ['I','V','X','L','C','D','M'];
value = [1 5 10 50 100 500 1000];
N = length(roman);
sv = zeros(1,N);
% Convert to decimal
for i=1:N
    idx = roman(i) == symbol;
    sv(i) = value(idx);
end
rt = 0;
max = 0;
% compute
for i = length(sv):-1:1
    if sv(i)>=max
        rt = rt+sv(i);
        max = sv(i);
    else
        rt = rt-sv(i);
    end
end
value = rt;
end