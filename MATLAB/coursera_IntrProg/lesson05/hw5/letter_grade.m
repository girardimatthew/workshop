function out = letter_grade(score)
if score >= 91
    out = 'A';
elseif score >= 81 && score <= 90
    out = 'B';
elseif score >= 71 && score <= 80
    out = 'C';
elseif score >= 61 && score <= 70
    out = 'D';
else
    out = 'F';
end