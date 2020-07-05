function plainText = natoToText(natoText)
% DESCRIPTION
% spells out a word (written in the NATO alphabet) in plain text.
% INTPUT
% natoText  :   Input in dash-separated NATO alphabet (string)
% OUTPUT
% plainText :   Output word in plain text (string)
idx = natoText == lower(natoText);
plainText = lower(natoText(~idx));
end