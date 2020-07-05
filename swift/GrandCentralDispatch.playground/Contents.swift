import UIKit

var space = {
    print("\n=====================================================\n")
}

func syncWork(){
    let northZone = DispatchQueue(label: "perform_task_with_team_north")
    let southZone = DispatchQueue(label: "perform_task_with_team_south")
    
    northZone.sync {
        for numer in 1...3{ print("North \(numer)")}
    }
    southZone.sync {
        for numer in 1...3{ print("South \(numer)") }
    }
}

//Call Func here
syncWork()

space()

func asyncWork(){
    let northZone = DispatchQueue(label: "perform_task_with_team_north")
    let southZone = DispatchQueue(label: "perform_task_with_team_south")
    
    northZone.async {
        for numer in 1...3{ print("North \(numer)") }
    }
    southZone.async {
        for numer in 1...3{ print("South \(numer)") }
    }
}

//Call Async Task
asyncWork()

space()

var shoppingList = ["key":"value"]

// Initialize the dictionary
func callSomeMethodWithParams(_ params: [AnyHashable: Any],
                              onSuccess success: @escaping (_ JSON: Any) -> Void,
                              onFailure failure: @escaping (_ error: Error?, _ params: [AnyHashable: Any]) -> Void) {
    
    print("\n" + String(describing: params))
    
    let error: Error? = NSError(domain:"", code:1, userInfo:nil)
    
    var responseArray: [Any]?
    responseArray = [1,2,3,4,5]
    
    if let responseArr = responseArray {
        success(responseArr)
    }
    if let err = error {
        failure(err, params)
    }
    
}

callSomeMethodWithParams(shoppingList, onSuccess: { (JSON) in
    print("\nSuccess. Response received...: " + String(describing: JSON))
}) { (error, params) in
    if let err = error {
        print("\nError: " + err.localizedDescription)
    }
    print("\nParameters passed are: " + String(describing:params))
}
