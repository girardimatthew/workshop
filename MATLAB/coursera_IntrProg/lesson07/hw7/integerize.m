function c = integerize(A)
    if A == uint8(A)
        c = 'uint8';
    elseif A == uint16(A)
        c = 'uint16';
    elseif A == uint32(A)
        c = 'uint32';
    elseif A == uint64(A)
        c = 'uint64';
    else
        c = 'NONE';
    end
end