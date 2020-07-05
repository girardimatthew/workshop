function pFemale = genderGuess(name)
vowels = ['a' 'e' 'i' 'o' 'u' 'y'];
f = 'f';
k = 'k';
if (sum(name(end) == vowels))==1
    if sum(name == f)>=2
        pFemale = 0.35;
    else
        pFemale = 0.87;
    end
else
    if name(1) == k
        pFemale = 0.69;
    else
        pFemale = 0.25;
    end
end
end