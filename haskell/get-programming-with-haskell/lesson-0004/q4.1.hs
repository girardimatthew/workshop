--q4.1
-- Anything that can be compared in Haskell (for example, [Char], which you use for the names in your name tuples) can be compared with a function called compare. The compare function returns GT, LT, or EQ. Rewrite compareLastNames by using compare.

import Data.List

-- compareNames name1 name2 = if (compare lastName1 lastName2) == EQ
--                                then compare firstName1 firstName2
--                                else compare lastName1 lastName2
                               

--     where lastName1 = snd name1
--           lastName2 = snd name2
--           firstName1 = fst name1
--           firstName2 = fst name2

compareLastNames name1 name2 = if result == EQ
                               then compare (fst name1) (fst name2)
                               else result
    where result = compare (snd name1) (snd name2)

names = [("Ian", "Curtis"),
         ("Bernard","Sumner MacKenzie"),
         ("Peter", "Hook Baldwin"),
         ("John", "Hook Baldwin"),
         ("Stephen","Morris")]