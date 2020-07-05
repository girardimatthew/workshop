import UIKit

func testRetainCycle() {
    print("\n" + #function)
    class Dog {
        deinit { print("farewell from Dog") }
    }
    
    class Cat {
        deinit { print("farewell from Cat") }
    }
    let _ = Dog()
    let _ = Cat()
}
testRetainCycle()

func testRetainCycle_inAction() {
    print("\n" + #function)
    class Dog {
        var cat: Cat?
        deinit { print("farewell from Dog") }
    }
    
    class Cat {
        var dog: Dog?
        deinit { print("farewell from Cat") }
    }
    let d = Dog()
    let c = Cat()
    d.cat = c // create a...
    c.dog = d // ...retain cycle
}
testRetainCycle_inAction()


func testRetainCycle_Fixed() {
    print("\n" + #function)
    class Dog {
        weak var cat: Cat?
        deinit { print("farewell from Dog") }
    }
    
    class Cat {
        weak var dog: Dog?
        deinit { print("farewell from Cat") }
    }
    let d = Dog()
    let c = Cat()
    d.cat = c
    c.dog = d
}
testRetainCycle_Fixed()


func testRetainCycle_WithValueTypes() {
    print("\n" + #function)
    class Dog {
        var cat: Cat?
        deinit { print("farewell from Dog") }
    }
    
    struct Cat {
        weak var dog: Dog?
    }
    let d = Dog()
    var c = Cat()
    d.cat = c
    c.dog = d
}
testRetainCycle_WithValueTypes()


// useful in special cases
func testRetainCycle_UnownedReferences() {
    print("\n" + #function)
    class Boy {
        var dog: Dog?
        deinit { print("farewell from Boy") }
    }
    
    class Dog {
        let boy: Boy
        init(boy: Boy) { self.boy = boy }
        deinit { print("farewell from Dog") }
    }
    let b = Boy()
    let d = Dog(boy: b)
    b.dog = d
}
testRetainCycle_UnownedReferences() // Nothing printed in the console


func testRetainCycle_UnownedReferences_Fixed() {
    print("\n" + #function)
    class Boy {
        var dog: Dog?
        deinit { print("farewell from Boy") }
    }
    
    class Dog {
        unowned let boy: Boy
        init(boy: Boy) { self.boy = boy }
        deinit { print("farewell from Dog") }
    }
    let b = Boy()
    let d = Dog(boy: b)
    b.dog = d
}
testRetainCycle_UnownedReferences_Fixed() // deinit methods are called.

// Unowned can be very dengerous
func testRetainCycle_UnownedReferences_Very_Dengerous() {
    print("\n" + #function)
    class Boy {
        var dog: Dog?
        deinit { print("farewell from Boy") }
    }
    
    class Dog {
        unowned let boy: Boy
        init(boy: Boy) { self.boy = boy }
        deinit { print("farewell from Dog") }
    }
    
    /* -- CRASH !!
    var b = Optional(Boy())
    let d = Dog(boy: b!)
    b = nil // destroy the boy behind the Dog's back
    print(d.boy)
    */
}
testRetainCycle_UnownedReferences_Very_Dengerous()
