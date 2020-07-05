-- GCD

myGCD a b = if reminder == 0
          then b
          else myGCD b reminder
    where reminder = a `mod` b 