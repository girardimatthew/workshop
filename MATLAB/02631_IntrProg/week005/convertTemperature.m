% function T = convertTemperature(T, unitFrom, unitTo)
% % Converts a temperature T between units of meaurement Fahrenheit,
% % Celsius and Kelvin.
% % INPUT: 
% %   T           : The input temperature (decimal number)
% %   unitFrom    : The unit of temperature of the input (string, Celsius, Fahrenheit, or Kelvin) 
% %   unitTo      : The unit of temperature of the output (string, Celsius, Fahrenheit, or Kelvin)
% % OUTPUT:
% %   T           : The converted temperature (decimal number)
% 
% % Const string
% fahr = 'Fahrenheit';
% cels = 'Celsius';
% kelv = 'Kelvin';
% % fahrenheit to celsius
% if strcmpi(fahr, unitFrom) && strcmp(cels, unitTo)
%     T = (T - 32)/1.8;
% % fahrenheit to kelvin
% elseif strcmpi(fahr, unitFrom) && strcmp(kelv, unitTo)
%     T = (T + 459.67)/1.8;
% % celsius to fahrenheit
% elseif strcmpi(cels, unitFrom) && strcmp(fahr, unitTo)
%     T = 1.8 * T + 32;
% % celsius to kelvin
% elseif strcmpi(cels, unitFrom) && strcmp(kelv, unitTo)
%     T = T + 273.15;
% % kelvin to fahrenheit
% elseif strcmpi(kelv, unitFrom) && strcmp(fahr, unitTo)
%     T = 1.8 * T - 459.67;
% % kelvin to celsius
% elseif strcmpi(kelv, unitFrom) && strcmp(cels, unitTo)
%     T = T - 273.15;
% % error
% else
%     disp('Error: wrong string input!');
% end
% end

%% Suggested solution
function T = convertTemperature(T, unitFrom, unitTo)
% Converts a temperature T between units of meaurement Fahrenheit,
% Celsius and Kelvin.
% Inputs
%    T         : Input temperature
%    unitFrom  : Unit to convert from
%    unitTo    : Unit to convert to
% Units can be either of the strings 'Fahrenheit', 'Celsius', or
% 'Kelvin'.
 
% The function is implemented by always converting to Kelvin and
% then converting to the desired unit.
 
% First, convert from unitFrom to Kelvin
if strcmpi(unitFrom, 'Celsius')
    K = T + 273.15;
elseif strcmpi(unitFrom, 'Fahrenheit')
    K = (T + 459.67) / 1.8;
else
    K = T;
end
 
% Next, convert from Kelvin to unitTo
if strcmpi(unitTo, 'Celsius')
    T = K - 273.15;
elseif strcmpi(unitTo, 'Fahrenheit')
    T = 1.8 * K - 459.67;
else
    T = K;
end