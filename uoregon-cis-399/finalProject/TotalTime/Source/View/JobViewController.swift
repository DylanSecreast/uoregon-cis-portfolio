//
//  JobViewController.swift
//  TotalTime
//
//  Created by Dylan Secreast on 3/1/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
//

import UIKit
import CoreData

class JobViewController : UIViewController {
    
    @IBOutlet weak var jobTitleField: UITextField!
    @IBOutlet weak var hourlyRateField: UITextField!
    
    @IBOutlet weak var clientNameField: UITextField!
    @IBOutlet weak var clientPhoneField: UITextField!
    @IBOutlet weak var clientEmailField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    @IBAction func saveButton(_ sender: Any) {
        
        let delegate = UIApplication.shared.delegate as! AppDelegate
        let context = delegate.persistentContainer.viewContext

        let job = Job(context: context)
        let client = Client(context: context)

        if (jobTitleField.text == "" || hourlyRateField.text == "" || clientEmailField.text == "") {
            let alertController = UIAlertController(title: "Not Enough Info", message: "Please enter Job Title, Hourly Rate, and Client Email to save", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            present(alertController, animated: true, completion: nil)
            return
        }

        job.title = jobTitleField.text
        job.hourlyRate = Float(hourlyRateField.text!)!
        job.secondsWorked = 0
        job.completed = false
        client.name = clientNameField.text
        client.email = clientEmailField.text
        
        delegate.saveContext()
        
        let alertController = UIAlertController(title: "Saved!", message: "Successfully saved " + jobTitleField.text!, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        present(alertController, animated: true, completion: nil)
        
        jobTitleField.text = ""
        hourlyRateField.text = ""
        clientNameField.text = ""
        clientEmailField.text = ""
    }
    
}
