function se = computeLanguageError(freq)
% takes as input a vector of frequencies of 
% occurrences of letters in a text. 
% read the file letter_frequencies.csv, 
% compute the squared error for each language, 
% and return a vector of squared errors for the fifteen languages.

% INPUT 
% freq  :   A vector of size 26 containing the 
%           frequency of the letters a?z in a text.
% OUTPUT
% se    :   A vector of length 15 containing the squared error 
%           between the input vector and each of the 
%           15 languages in the CSV file

lFreq = readtable('letter_frequencies.csv');
[~,c] = size(lFreq);
se = zeros(1,c-1);
for i = 2:c
    se(i-1) = sum((freq'-lFreq{:,i}).^2);
end
end