import UIKit

// =================================
// Memory management of protocol-types references
//


class SecondViewController: UIViewController {
    
    weak var delegate: SecondViewControllerDelegate?
}

protocol SecondViewControllerDelegate: class {
    func accept(data: Any!)
}
