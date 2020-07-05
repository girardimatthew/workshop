% Using no if-statements

function a = older_v02(y1,m1,d1,y2,m2,d2)
    a1 = y1 * 372 + m1 * 31 + d1;     % does not have to be exact date in days 
    a2 = y2 * 372 + m2 * 31 + d2;     % it simply makes a1 and a2 comparable
    a = sign(a2 - a1);                % sign() returns -1, 0 or 1, just what is needed
end

% multiplying by 372  (12 * 31) or greater is needed 