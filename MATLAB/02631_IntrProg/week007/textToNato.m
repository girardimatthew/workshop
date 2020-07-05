function natoText = textToNato(plainText)
% DESCRIPTION
% spells out a word (written in plain text) in the NATO alphabet.
% INPUT
% plainText :   Input word in plain text (string)
% OUTPUT
% natoText  :   Output in dash-separated NATO alphabet (string)

NATO = {'Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', ...
    'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliet', 'Kilo', ...
    'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', ...
    'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', ...
    'Xray', 'Yankee', 'Zulu'};
alpha = ['a':'z'];
plainText = lower(plainText);
natoText = [];
for i = 1:length(plainText)
    x = alpha == plainText(i);
    natoText = strcat(natoText,NATO(x),'-');
end
natoText = natoText{1}(1:end-1);
end