%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Introduction to Programming and Data Processing
% module 007 - Assignments
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Assignment 7G The NATO alphabet
clear all; close all; clc;
W = {'Hello', 'abcdefghi', 'jklmnopqr', 'stuvwxyz', 'CAPITALS', 'MiXedCase'};
for i = 1:length(W)
    N{i} = textToNato(W{i});
end
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Assignment 7H - Back to plain text
for i = 1:length(N)
    natoToText(N{i})
end

