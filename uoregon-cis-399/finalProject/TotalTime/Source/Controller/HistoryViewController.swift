//
//  HistoryViewController.swift
//  TotalTime
//
//  Created by Dylan Secreast on 3/8/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
//

import UIKit

class HistoryViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var tableView: UITableView!
    
    var jobs: [Job] = []
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.dataSource = self
        tableView.delegate = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        getData()
        tableView.reloadData()
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return jobs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell()
        let job = jobs[indexPath.row]
        
        cell.textLabel?.text = job.title
        
        return cell
    }
    
    func getData() {
        let delegate = UIApplication.shared.delegate as! AppDelegate
        let context = delegate.persistentContainer.viewContext
        
        do {
            jobs = try context.fetch(Job.fetchRequest())
        }
        catch {
            print("Error fetching jobs")
        }
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        let delegate = UIApplication.shared.delegate as! AppDelegate
        let context = delegate.persistentContainer.viewContext
        
        if editingStyle == .delete {
            let job = jobs[indexPath.row]
            context.delete(job)
            delegate.saveContext()
            
            do {
                jobs = try context.fetch(Job.fetchRequest())
            }
            catch {
                print("Error fetching jobs")
            }
        }
        tableView.reloadData()
    }
    
}
