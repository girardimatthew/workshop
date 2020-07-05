function num = inputNumber(prompt)
% INPUTNUMBER Prompts user to input a number
%
% Usage: num = inputNumber(prompt) Displays prompt and asks user to input a
% number. Repeats until user inputs a valid number.
%
% Author: Mikkel N. Schmidt, mnsc@dtu.dk, 2015

%% menu from 1 to length
% while true
%     num = str2double(input(prompt,'s'));
%     if ~isnan(num)
%         break; 
%     end
% end

%% menu from 0 to length-1
% while true
%     num = str2double(input(prompt,'s'));
%     num = num + 1;
%     if ~isnan(num)
%         break; 
%     end
% end

%% menu using letters
while true
    num = (input(prompt,'s') - 96);
    if ~isnan(num)
        break; 
    end
end