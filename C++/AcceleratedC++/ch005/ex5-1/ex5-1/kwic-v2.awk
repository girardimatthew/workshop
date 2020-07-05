#!/usr/bin/awk
# kwic - generate kwic index
# version 2

{ 
    for (i = 1; i < length($0); i++)
        if (substr($0, i, 1) == " ")
            printf("%15s%s\n",
                substr($0, i-15, (i<=15 ? i-1 : 15)),
                substr($0, i, 15))
}