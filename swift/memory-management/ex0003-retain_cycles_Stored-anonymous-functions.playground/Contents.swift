import UIKit

// =================================
// STORED ANONYMOUS FUNCTIONS
//

func test_FunctionHolderWithRetainCycle() {
    print("\n" + #function)
    class FunctionHolder {
        var function: (() -> ())?
        deinit { print("\t - farewell from FunctionHolder") }
    }
    func testFunctionHolder() {
        let fh = FunctionHolder()
        fh.function = {
            print(fh)
        }
    }
    testFunctionHolder() // Nothing in the console
}
test_FunctionHolderWithRetainCycle()


func test_FunctionHolder() {
    print("\n" + #function)
    class FunctionHolder {
        var function: (() -> ())?
        deinit { print("\t - farewell from FunctionHolder") }
    }
    func testFunctionHolder() {
        let fh = FunctionHolder()
        fh.function = { [weak fh] in
            print(fh)
        }
    }
    testFunctionHolder() // Nothing in the console
}
test_FunctionHolder()

func test_FunctionHolder_WeakStrongDance() {
    print("\n" + #function)
    class FunctionHolder {
        var function: (() -> ())?
        deinit { print("\t - farewell from FunctionHolder") }
    }
    func testFunctionHolder() {
        let fh = FunctionHolder()
        fh.function = { [weak fh] in
            guard let fh = fh else { return }
            print(fh)
        }
    }
    testFunctionHolder() // Nothing in the console
}
test_FunctionHolder_WeakStrongDance()


func test_FunctionHolder_ShouldBeUnowned() {
    print("\n" + #function)
    class FunctionHolder {
        var function: (() -> ())?
        deinit { print("\t - farewell from FunctionHolder") }
    }
    func testFunctionHolder() {
        let fh = FunctionHolder()
        fh.function = { [unowned fh] in
            print(fh)
        }
    }
    testFunctionHolder() // Nothing in the console
}
test_FunctionHolder_ShouldBeUnowned()
