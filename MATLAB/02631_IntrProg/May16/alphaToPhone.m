function phone = alphaToPhone(alpha)
L = length(alpha);
phone = alpha;
for i = 1:L
    if alpha(i) == 'A' || alpha(i) == 'B' || alpha(i) == 'C'
        phone(i) = '2';
    elseif alpha(i) == 'D' || alpha(i) == 'E' || alpha(i) == 'F'
        phone(i) = '3';
    elseif alpha(i) == 'G' || alpha(i) == 'H' || alpha(i) == 'I'
        phone(i) = '4';
    elseif alpha(i) == 'J' || alpha(i) == 'K' || alpha(i) == 'L'
        phone(i) = '5';
    elseif alpha(i) == 'M' || alpha(i) == 'N' || alpha(i) == 'O'
        phone(i) = '6';
    elseif alpha(i) == 'P' || alpha(i) == 'Q' || alpha(i) == 'R' || alpha(i) == 'S'
        phone(i) = '7';
    elseif alpha(i) == 'T' || alpha(i) == 'U' || alpha(i) == 'V'
        phone(i) = '8';
    elseif alpha(i) == 'W' || alpha(i) == 'X' || alpha(i) == 'Y' || alpha(i) == 'Z' 
        phone(i) = '9';
    else
        phone(i) = alpha(i);
    end
end
end

%% suggested solution
% function phone = alphaToPhone(alpha)
% 
% % Convert to upper case (not necessary)
% phone = upper(alpha);
% 
% % List of letters and their replacement
% letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
% digits =  '22233344455566677778889999';
% 
% % Loop through alpha
% for i = 1:length(phone)
%     % If character is a letter on the list
%     if any(phone(i) == letters)
%         % Convert to digit
%         phone(i) = digits(phone(i) == letters);
%     end
% end