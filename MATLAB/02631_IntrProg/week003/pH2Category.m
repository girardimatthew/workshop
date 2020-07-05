function category = pH2Category(pH)
% Computes the category (string) corresponding to the input pH
% value (number)

if (pH < 0 || pH > 14)
    category = 'pH out of range';
elseif (pH < 3)
    category = 'Strongly acidic';
elseif (pH < 6)
    category = 'Weakly acidic';
elseif (pH <= 8)
    category = 'Neutral';
elseif (pH <= 11)
    category = 'Weakly basic';
else
    category = 'Strongly basic';
end