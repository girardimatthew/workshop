% Using no if-statement

function cando = movies_v02(h1,m1,d1,h2,m2,d2)
    end1 = h1*60 + m1 + d1;
    st2  = h2*60 + m2;
    cando = (end1 <= st2 && end1+30 >= st2);
end