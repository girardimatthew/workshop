--genIfEven
--

inc n = n+1
double n = n*2
square n = n^2
cube n = n^3

ifEven myFunction x = if even x
                      then myFunction x 
                      else x

-- USAGE: genIfEven inc 6
genIfEven f = (\x -> ifEven f x)


--Write a function genIfXEven that creates a closure with x and 
--returns a new function that allows the user to pass 
--in a function to apply to x if x is even.

-- USAGE: genIfXEven 4 inc
genIfXEven x = (\f -> ifEven f x)

-- order arguments from most to least general
-- general arguments should appear first in the argument list
getRequestURL host apiKey resource id = host ++
                                        "/" ++
                                        resource ++
                                        "/" ++
                                        id ++
                                        "?token=" ++
                                        apiKey

genHostRequestBuilder host = (\apiKey resource id -> 
    getRequestURL host apiKey resource id)

genApiRequestBuilder hostBuilder apiKey = (\resource id -> 
    hostBuilder apiKey resource id)

-- QC 5.2
genApiResourceRequestBuilder hostBuilder apiKey resource = (\id -> 
    hostBuilder apiKey resource id)

-- QC 5.3
-- exampleBuilder = getRequestUrl "http://example.com" "1337hAsk3ll" "books"
genIdRequestBuilder id = (\host apiKey resource -> 
    getRequestURL host apiKey resource id)