function BMIGroup = classifyBMI(height, weight)
%BMIGroup
%   this function takes the height and weight as 
%   numeric inputs and returns the BMI group as a string
%   
%   USAGE:
%   BMIGroup = classifyBMI(height, weight)
%
%   INPUT
%   - height:       Height in meters (decimal number)
%   - weight:       Weight in kilograms (decimal number)    
%
%   OUTPUT
%   - BMIGroup:     BMI group (string)
%
if height<0
    fprintf(2,'Error in classifyBMI: height is negative.\n');
    return;
end
if weight<0
    fprintf(2,'Error in classifyBMI: weight is negative.\n');
    return;
end
BMIGroup = '';
b = weight/(height^2);
group = {'Severely underweight', 'Underweight', 'Normal', 'Overweight', ...
    'Obese', 'Severely obese'};
if b<16
    BMIGroup = 'Severely underweight';
elseif b>=16 && b<18.5
    BMIGroup = 'Underweight';
elseif b>=18.5 && b<25
    BMIGroup = 'Normal';
elseif b>=25 && b<30
    BMIGroup = 'Overweight';
elseif b>=30 && b<40
    BMIGroup = 'Obese';
elseif b>=40
    BMIGroup = 'Severely obese';
else
    fprintf(2,'Error in classifyBMI.\n');
end
end