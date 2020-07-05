import UIKit

// ==================================================
// Weak references
// ==================================================

class Human {
    //weak var bestFriend: Dog?
    var bestFriend: Dog?
    
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    deinit {
        print("\(name) is being removed.")
    }
}

class Dog {
    // weak var master: Human?
    var master: Human?
    
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    deinit {
        print("\(name) is being removed.")
    }
}


var turner: Human? = Human(name: "Turner")
var hooch: Dog? = Dog(name: "Hooch")

// Setting our variables as optional, easiest way of releasing
// owenership on a variable
//turner = nil
//hooch = nil

// - refer to one another.
// strong references! They are both owners to each other
turner?.bestFriend = hooch
hooch?.master = turner

// set our variables to nil
turner = nil
hooch = nil



// ==================================================
// Unowned references
// ==================================================


class Person {
    var name: String
    var passpord: Passport?
    
    init(name: String) {
        self.name = name
    }
    
    deinit { print("\(name) is being removed.") }
}

class Passport {
    var number: Int
    unowned let person: Person
    
    init(number: Int, person: Person) {
        self.number = number
        self.person = person
    }
    
    deinit { print("Password \(number) is being removed.") }
}

var viktor: Person? = Person(name: "Viktor Novarski")
viktor?.passpord = Passport(number: 1234567890, person: viktor!)
viktor?.passpord?.number

viktor = nil
//viktor?.passpord = nil

