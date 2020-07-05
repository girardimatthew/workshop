function choice = displayMenu(options)
% DISPLAYMENU Displays a menu of options, ask the user to choose an item
% and returns the number of the menu item chosen.
%
% Usage: choice = displayMenu(options)
%
% Input    options   Menu options (cell array of strings)
% Output   choice    Chosen option (integer)
%
% Author: Mikkel N. Schmidt, mnsc@dtu.dk, 2015

%% v001 - from 1 to length
% % Display menu options
% for i = 1:length(options)
%     fprintf('%d. %s\n', i, options{i});
% end
% 
% % Get a valid menu choice
% choice = 0;
% while ~any(choice == 1:length(options))
%     choice = inputNumber('Please choose a menu item: ');
% end

%% v002 - from 0 to length
% Display menu options
% for i = 1:length(options)
%     fprintf('%d. %s\n', i-1, options{i});
% end
% 
% % Get a valid menu choice
% choice = 0;
% while ~any(choice == 1:length(options))
%     choice = inputNumber('Please choose a menu item: ');
% end

%% v003 - using letters
% Display menu options
l = ['a':'z', 'A':'Z'];
for i = 1:length(options)
    fprintf('%s. %s\n', l(i), options{i});
end

% Get a valid menu choice
choice = 0;
while ~any(choice == 1:length(options))
    choice = inputNumber('Please choose a menu item: ');
end