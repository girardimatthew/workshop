function stack = RPNCalculator(commands)
%RPNCalculator
%   this function takes as input a text string defining 
%   an sequence of commands in reverse Polish notation. 
%   The commands are either numbers or one of the strings +, -, s, 
%   and are separated by space. 
%   The function must output the final state of the stack 
%   (as a vector) after performing the given operations.
%   
%   USAGE:
%   stack = RPNCalculator(commands)
%
%   INPUT
%   - commands:         Sequence of commands (string)
%
%   OUTPUT
%   - stack:            Value of the stack (vector)
%
stack = [];
commands = strsplit(commands);
idx = 0;
for i = 1:length(commands)
    lenS = length(stack);
    n = str2double(commands(i));
    if ~isnan(n)
        stack = [stack, n];
    else
        if char(commands(i)) == '-'
            if lenS==1
                fprintf(2,'Error: The user has not input sufficient values in the expression.\n');
                stack = -1;
                return;
            end
            tmp = stack(end-1) - stack(end);
            if lenS>2 
                stack = [stack(1:end-2), tmp];
            else
                stack = tmp;
            end
        elseif char(commands(i)) == '+'
            if lenS==1
                fprintf(2,'Error: The user has not input sufficient values in the expression.\n');
                stack = -1;
                return;
            end
            tmp = stack(end-1) + stack(end);
            if lenS>2
                stack = [stack(1:end-2), tmp];
            else
                stack = tmp;
            end
        elseif char(commands(i)) == 'x'
            if lenS==1
                fprintf(2,'Error: The user has not input sufficient values in the expression.\n');
                stack = -1;
                return;
            end
            tmp = stack(end-1) * stack(end);
            if lenS>2
                stack = [stack(1:end-2), tmp];
            else
                stack = tmp;
            end
        elseif char(commands(i)) == 's'
            if lenS==1
                fprintf(2,'Error: The user has not input sufficient values in the expression.\n');
                stack = -1;
                return;
            end
            stack = [stack(1:end-2), stack(end), stack(end-1)];
        end
    end
end
end

% % function stack = RPNCalculator(commands)
% %  
% % % Split command string
% % splitCommands = strsplit(commands, ' ');
% %  
% % % Number of commands
% % N = length(splitCommands);
% %  
% % % Initial stack
% % stack = [];
% %  
% % % Loop over commands
% % for i = 1:N
% %     % Add last two numbers on the stack
% %     if splitCommands{i} == '+'
% %         stack = [stack(1:end-2) stack(end-1)+stack(end)];
% %          
% %     % Subtract last two numbers on the stack
% %     elseif splitCommands{i} == '-'
% %         stack = [stack(1:end-2) stack(end-1)-stack(end)];
% %          
% %     % Swap last two numbers on the stack
% %     elseif splitCommands{i} == 's'
% %         stack = [stack(1:end-2) stack(end) stack(end-1)];
% %          
% %     % Push a number onto the stack
% %     else
% %         stack = [stack str2double(splitCommands{i})];
% %     end
% % end