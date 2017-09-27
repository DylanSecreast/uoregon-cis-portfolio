//
//  MainViewController.swift
//  Assignment3
//
//  Created by Dylan Secreast on 1/25/17.
//  Copyright © 2017. All rights reserved.
//

import Foundation
import UIKit


class MainViewController: UIViewController {
    // MARK: Initialization
    required override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    // MARK: View Life Cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        launchLabel.text = "Launched at \(Date())"
    }
    
    
    // MARK: Properties (IBOutlet)
    @IBOutlet private weak var launchLabel: UILabel! = nil
}
