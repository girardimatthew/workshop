function pagesBooklet = bookPages(pagesContent)
%bookPages
%   this function takes as input the number of pages of content you have 
%   for the booklet and returns the number of pages (a multiple of 4) 
%   in the smallest booklet that can accomodate your content.
%   
%   USAGE:
%   pagesBooklet = bookPages(pagesContent)
%
%   INPUT
%   - pagesContent:     Number of pages of content (whole number).
%
%   OUTPUT
%   - pagesBooklet:     Number of pages in booklet (whole number)
%
p = 0;
while p<pagesContent
    p = p+4;
end
pagesBooklet = p;
end