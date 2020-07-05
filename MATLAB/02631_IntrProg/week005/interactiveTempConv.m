function interactiveTempConv()

% Check for valid number
while true 
    x = str2double(input('Please input a temperature:  ','s'));
    if ~isnan(x)
        break;
    end
    disp('Not valid number. Please try again');
end
% Check for valid unitFrom
while true
    unitFrom = input('Please input the unit of temperature (Celsius, Fahrenheit, or Kelvin): ', 's');
    if strcmpi(unitFrom,'Celsius') || strcmpi(unitFrom,'Fahrenheit') || strcmpi(unitFrom,'Kelvin')
        break;
    elseif strcmpi(unitFrom,'C')
        unitFrom = 'Celsius';
        break;
    elseif strcmpi(unitFrom,'F')
        unitFrom = 'Fahrenheit';
        break;
    elseif strcmpi(unitFrom,'K')
        unitFrom = 'Kelvin';
        break;
    end
    disp('Not valid string. Please try again');
end
% Check for valid unitTo
while true
    unitTo = input('Please input the unit to convert to (Celsius, Fahrenheit, or Kelvin): ', 's');
    if strcmpi(unitTo,'Celsius') || strcmpi(unitTo,'Fahrenheit') || strcmpi(unitTo,'Kelvin')
        break;
    elseif strcmpi(unitTo,'C')
        unitTo = 'Celsius';
        break;
    elseif strcmpi(unitTo,'F')
        unitTo = 'Fahrenheit';
        break;
    elseif strcmpi(unitTo,'K')
        unitFrom = 'Kelvin';
        break;
    end
    disp('Not valid string. Please try again');
end
% convert 
y = convertTemperature(x, unitFrom, unitTo);
fprintf('%d %s = %d %s\n', x, unitFrom, y, unitTo);
end