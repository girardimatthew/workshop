-- constructor
-- robot ("Kill3r",25,200)
robot (name,attack,hp) = \message -> message (name,attack,hp)

-- helper functions
name (n,_,_) = n
attack (_,a,_) = a
hp (_,_,hp) = hp

-- accessors
getName aRobot = aRobot name
getAttack aRobot = aRobot attack
getHP aRobot = aRobot hp

-- nicerRobot = setName killerRobot "kitty"
setName aRobot newName = aRobot (\(n,a,h) -> robot (newName,a,h))
-- gentlerRobot = setAttack killerRobot 5
setAttack aRobot newAttack = aRobot (\(n,a,h) -> robot (n,newAttack,h))
-- softerRobot = setHP killerRobot 50
setHP aRobot newHP = aRobot (\(n,a,h) -> robot (n,a,newHP))

printRobot aRobot = aRobot (\(n,a,h) -> n ++
                                        " attack:" ++ (show a) ++
                                        " hp:" ++ (show h))

-- damage function
damage aRobot attackDamage = aRobot (\(n,a,h) -> 
                                      robot (n,a,h-attackDamage))

-- fight function 
fight aRobot defender = damage defender attack 
    where attack = if getHP aRobot > 10
                   then getAttack aRobot
                   else 0

-- gentleGiantRound1 = fight killerRobot gentleGiant
-- killerRobotRound1 = fight gentleGiant killerRobot
-- gentleGiantRound2 = fight killerRobotRound1 gentleGiantRound1
-- killerRobotRound2 = fight gentleGiantRound1 killerRobotRound1
-- gentleGiantRound3 = fight killerRobotRound2 gentleGiantRound2
-- killerRobotRound3 = fight gentleGiantRound2 killerRobotRound2

-- listing 10.16 Changing the priority of attacks
-- correct order

-- fastRobot = robot ("speedy", 15, 40)
-- slowRobot = robot ("slowpoke",20,30)

-- slowRobotRound1 = fight fastRobot slowRobot
-- fastRobotRound1 = fight slowRobotRound1 fastRobot

-- slowRobotRound2 = fight fastRobotRound1 slowRobotRound1
-- fastRobotRound2 = fight slowRobotRound2 fastRobotRound1 

-- slowRobotRound3 = fight fastRobotRound2 slowRobotRound2
-- fastRobotRound3 = fight slowRobotRound3 fastRobotRound2