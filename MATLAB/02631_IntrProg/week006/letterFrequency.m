function freq = letterFrequency(filename)

% INPUT
% filename  :   A string that is the filename of a plain text file in the current working directory.
% OUTPUT
% freq      :   A vector of length 26 containing the frequency of occurrence of each of the 26 letters from a to z.
smalltxt = fileread(filename);
stLower = lower(smalltxt);
alpha = ['a':'z'];
count = zeros(1,length(alpha));
for i = 1:length(stLower)
    count = count + (stLower(i) == alpha);
end
tOccur = sum(count);
freq = (count/tOccur)*100;
end