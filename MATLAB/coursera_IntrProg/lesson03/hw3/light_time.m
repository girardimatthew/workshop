function [min, km] = light_time(ml)
km = ml * 1.609;
min = (km/300000)/60;
end