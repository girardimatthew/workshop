%% Age groups
clear all; close all; clc;
computeAgeGroup(2.9)
computeAgeGroup(0.5)
computeAgeGroup(1.0)
computeAgeGroup(1.5)
computeAgeGroup(3.0)
computeAgeGroup(13.0)
computeAgeGroup(17.5)
computeAgeGroup(19.99)
computeAgeGroup(20.0)
computeAgeGroup(0.0)
computeAgeGroup(123.45)
%% Shirt sizes
clear all; close all; clc;
computeShirtSize(43.5,34.2)
computeShirtSize(45.9, 41.5)
%% Air conditioning system
clear all; close all; clc;
state = [0 1 2 3 2 3 1];
timestamp = [0 486 849 1250 2340 3560 7045];
acState(state,timestamp)
acState([0, 1, 4, 2, 3, 2, 1], [0, 100, 200, 300, 400, 500, 600])
acState([0, 4, 0, 4, 0], [0, 1, 100, 101, 200])
acState([0, 4, 0], [0, 50, 50])
acState([0, 1, 2, 3, 4], [0, 123, 456, 789, 101112])
acState([0, 1, 2, 3, 4, 3, 2, 1, 0], [0, 1, 2, 3, 4, 5, 6, 7, 8])
acState([0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], [0, 5, 7, 9, 13, 18, 25, 36, 37, 39, 50, 180, 186, 189, 190, 1024, 1056, 1159])
acState([0, 4, 0], [0, 0, 1000])
%% Morse code
clear all; close all; clc;
morseToText('-- --- .-. ... .  -.-. --- -.. .')
morseToText('. -.. --- -.-.  . ... .-. --- --')
morseToText('--  ---  .-.  ...  .  -.-.  ---  -..  .')
morseToText('-- -- -- --  -- -- -- --  -- -- -- --')
morseToText('... --- ...')
morseToText('.- -... -.-. -.. . ..-. --. .... ..')
morseToText('.--- -.- .-.. -- -. --- .--. --.- .-.')
morseToText('..  .-.. --- ...- .  - ---  -.-. --- -.. .')
morseToText('.- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..')
morseToText('.-  -...  -.-.  -..  .  ..-.  --.  ....  ..  .---  -.-  .-..  --  -.  ---  .--.  --.-  .-.  ...  -  ..-  ...-  .--  -..-  -.--  --..')
%% The D?Hondt method
clear all; close all; clc;
dhondt([340000, 280000, 160000, 60000, 15000], 7)
dhondt([10000, 20000, 40000, 80000], 9)
dhondt([123456], 1)
dhondt([2, 3, 4, 5, 6, 7, 8, 9, 1, 10, 11, 12, 13, 14, 15], 119)
dhondt([10000, 20000, 40000, 80000], 9)
dhondt([10000, 20000, 55156], 30)
dhondt([11205, 20217], 10)
dhondt([1534, 350548, 151597, 486000, 15488, 45369, 41578], 179)






