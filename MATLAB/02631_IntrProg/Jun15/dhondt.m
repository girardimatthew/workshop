function seatsAllocated = dhondt(votes, seats)
seatsAllocated = zeros(1,length(votes));
for i = 1:seats
    q = votes./(seatsAllocated+1);
    idx = q == max(q);
    if sum(idx)>1
        idx = idx & (votes == max(votes(idx)));
    end
    seatsAllocated(idx) = seatsAllocated(idx) + 1;
end
end