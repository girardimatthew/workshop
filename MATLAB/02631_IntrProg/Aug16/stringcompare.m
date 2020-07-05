function disSimilarity = stringcompare(string1, string2)
%voldif
%   this function takes as input two strings and returns
%   their dis-similarity.
%   
%   USAGE:
%   disSimilarity = stringcompare(string1, string2)
%
%   INPUT
%   - string1:          Strings to be compared (string)
%   - string2:          Strings to be compared (string)
%
%   OUTPUT
%   - disSimilarity:    Dis-similarity measure (integer)
%
dict = ['a':'z'];
disSimilarity = 0;
for w = 1:length(dict)
    if (sum(dict(w) == string1) + sum(dict(w) == string2)) == 1
        disSimilarity = disSimilarity + 1;
    elseif sum(dict(w) == string1) > 0 && sum(dict(w) == string2) == 0
        disSimilarity = disSimilarity + 1;
    elseif sum(dict(w) == string2) > 0 && sum(dict(w) == string1) == 0
        disSimilarity = disSimilarity + 1;
    end
end
end