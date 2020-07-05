function text = morseToText(morseCode)
phrase = strsplit(morseCode,'  ');
W = length(phrase);
morse = {'.-','-...','-.-.','-..','.','..-.','--.','....','..','.---','-.-','.-..','--','-.','---',...
    '.--.','--.-','.-.','...','-','..-','...-','.--','-..-','-.--','--..'};
alpha = 'A':'Z';
text = '';
for i = 1:W
    n = strsplit(phrase{i});
    for j = 1:length(n)
        idx = ismember(morse,n(j));
        text = [text, alpha(idx)];
    end
    text = [text, ' '];
end
end