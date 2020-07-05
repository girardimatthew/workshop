import UIKit

// Define a protocol that has a function called handleIntruder
protocol HouseSecurityDelegate {
    func handleIntrude()
}

class House {
    
    var delegate: HouseSecurityDelegate?
    
    func burglarDetected() {
        // Check to see if the delegate is there, then call it
        delegate?.handleIntrude()
    }
}

class GuardDog: HouseSecurityDelegate {
    func handleIntrude() {
        print("Releasing the hounds!")
    }
}

class KillerRobot: HouseSecurityDelegate {
    func handleIntrude() {
        print("Deploying T-800 battle chasis")
    }
}

let myHouse = House()
myHouse.burglarDetected() // does nothing

let theHounds = GuardDog()
myHouse.delegate = theHounds
myHouse.burglarDetected() // does something

let killerRobot = KillerRobot()
myHouse.delegate = killerRobot
myHouse.burglarDetected()



