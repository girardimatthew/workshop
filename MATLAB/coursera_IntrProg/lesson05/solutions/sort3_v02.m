% Using no if-statements
function v = sort3_v02 (a,b,c)
    v = [a b c];                                % unordered
    v = [min(v(1),v(3)) v(2) max(v(1),v(3))];   % the 1st and 3rd are in order
    v = [min(v(1),v(2)) max(v(1),v(2)) v(3)];   % move 2nd left if necessary
    v = [v(1) min(v(2),v(3)) max(v(2),v(3))];   % move 2nd right if necessary
end