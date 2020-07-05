function coded = codeit(txt)
    coded = [];
    for jj = 1:length(txt)
        coded(jj) = 0;
    end
    toascii = double(txt);
    for ii = 1:length(toascii)
        if toascii(ii) >= 97 && toascii(ii) <= 122
            coded(ii) = ((122 - toascii(ii)) + 97);
        elseif toascii(ii) >= 65 && toascii(ii) <= 90
            coded(ii) = ((90 - toascii(ii)) + 65);
        else
            coded(ii) = toascii(ii);
        end
    end
    coded = char(coded);
end