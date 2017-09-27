//
//  DoneViewController.swift
//  TotalTime
//
//  Created by Dylan Secreast on 3/17/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
//

import Foundation
import CoreData
import UIKit
import Contacts
import MessageUI

class DoneViewController :  UIViewController, NSFetchedResultsControllerDelegate, MFMailComposeViewControllerDelegate {
    @IBOutlet weak var currentJobLabel: UILabel!
    @IBOutlet weak var TotalTimeWorkedLabel: UILabel!
    @IBOutlet weak var hourlyRateLabel: UILabel!
    @IBOutlet weak var invoiceTotalLabel: UILabel!
    
    @IBOutlet weak var clientEmailLabel: UILabel!
    
    private var jobFetchedResultsController: NSFetchedResultsController<Job>!
    private var clientFetchedResultsController: NSFetchedResultsController<Client>!
    
    var jobs: [Job] = []
    var clients: [Client] = []
    
    func fetchData() {
        jobFetchedResultsController = TimeService.shared.jobData()
        clientFetchedResultsController = TimeService.shared.clientData()
        
        jobFetchedResultsController.delegate = self
        clientFetchedResultsController.delegate = self
        
        jobs = jobFetchedResultsController.fetchedObjects!
        clients = clientFetchedResultsController.fetchedObjects!
        
        currentJobLabel.text = jobs.last?.title
        
        
        if (jobs.count == 0) {
            hourlyRateLabel.text = "$XX.XX"
        }
        else {
            hourlyRateLabel.text = "$" + (jobs.last?.hourlyRate.description)!
        }
        
        if (clients.count == 0) {
            clientEmailLabel.text = ""
        }
        else {
//            clientEmailLabel.text = clients[0].email
        }
        
    }
    
    private func checkContactAuthorizationStatus(_ contactOperation: @escaping () -> Void) {
        switch CNContactStore.authorizationStatus(for: .contacts) {
        case .authorized:
            contactOperation()
        case .notDetermined:
            let contactStore = CNContactStore()
            contactStore.requestAccess(for: .contacts, completionHandler: { (granted: Bool, error: Error?) -> Void in
                if granted {
                    contactOperation()
                }
                else {
                    let alertController = UIAlertController(title: "Contacts Error", message: "Contacts access is required, please check your privacy settings and try again.", preferredStyle: .alert)
                    alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
                    self.present(alertController, animated: true, completion: nil)
                }
            })
        default:
            let alertController = UIAlertController(title: "Contacts Error", message: "Contacts access is required, please check your privacy settings and try again.", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            present(alertController, animated: true, completion: nil)
        }
    }
    
    func mailComposeController(_ controller: MFMailComposeViewController, didFinishWith result: MFMailComposeResult, error: Error?) {
        dismiss(animated: true, completion: nil)
    }
    
    private func presentMailCompositionView(withRecipient recipient: String) {
        if MFMailComposeViewController.canSendMail() {
            let mailComposeViewController = MFMailComposeViewController()
            mailComposeViewController.mailComposeDelegate = self
            
            mailComposeViewController.setToRecipients([recipient])
            mailComposeViewController.setSubject("Completed Job")
            mailComposeViewController.setMessageBody("Finished job", isHTML: false)
            
            present(mailComposeViewController, animated: true, completion: nil)
        }
        else {
            let alertController = UIAlertController(title: "Cannot Send Email", message: "Please go to your Settings app and configure an email account", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            present(alertController, animated: true, completion: nil)
        }
    }
    
    @IBAction func sendInvoice(_ sender: Any) {
        checkContactAuthorizationStatus() {
            var success = false
            let fetchRequest = CNContactFetchRequest(keysToFetch: [CNContactEmailAddressesKey as CNKeyDescriptor])
            fetchRequest.predicate = CNContact.predicateForContacts(withIdentifiers: [self.clientEmailLabel.text!])
            
            let contactStore = CNContactStore()
            var clientContact: CNContact? = nil
            do {
                try contactStore.enumerateContacts(with: fetchRequest, usingBlock: { (contact, stop) -> Void in
                    clientContact = contact
                    stop.pointee = true
                })
                
                if let someClientContact = clientContact, let emailAddress = someClientContact.emailAddresses.first?.value as? String {
                    success = true
                    self.presentMailCompositionView(withRecipient: emailAddress)
                }
                else {
                    print("Contact not found or contact has no email address")
                }
            }
            catch let error {
                print("Error trying to enumerate contacts: \(error as NSError)")
            }
            
            if !success {
                let alertController = UIAlertController(title: "No Client Found", message: "Could not send email to \(self.clientEmailLabel.text)", preferredStyle: .alert)
                alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
                self.present(alertController, animated: true, completion: nil)
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        fetchData()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}
