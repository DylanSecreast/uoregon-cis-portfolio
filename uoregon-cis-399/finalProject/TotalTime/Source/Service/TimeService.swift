//
//  TimeService.swift
//  TotalTime
//
//  Created by Dylan Secreast on 3/1/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
// 

import CoreData


class TimeService {
    
    func jobData() -> NSFetchedResultsController<Job> {
        let fetchRequest: NSFetchRequest<Job> = Job.fetchRequest()
        fetchRequest.sortDescriptors = [NSSortDescriptor(key:"title", ascending: false)]
        return fetchedResultsController(for: fetchRequest)
    }
    
    func clientData() -> NSFetchedResultsController<Client> {
        let fetchRequest: NSFetchRequest<Client> = Client.fetchRequest()
        fetchRequest.sortDescriptors = [NSSortDescriptor(key:"email", ascending: false)]
        return fetchedResultsController(for: fetchRequest)
    }
    
    // MARK: Private
    func fetchedResultsController<T>(for fetchRequest: NSFetchRequest<T>) -> NSFetchedResultsController<T> {
        let fetchedResultsController = NSFetchedResultsController(fetchRequest: fetchRequest, managedObjectContext: persistentContainer.viewContext, sectionNameKeyPath: nil, cacheName: nil)
        do {
            try fetchedResultsController.performFetch()
        }
        catch let error {
            fatalError("Could not perform fetch for fetched results controller: \(error)")
        }
        
        return fetchedResultsController
    }
    
    // MARK: Initialization
    private init() {
        persistentContainer = NSPersistentContainer(name: "TotalTime")
        persistentContainer.loadPersistentStores(completionHandler: { (storeDescription, error) in
            let context = self.persistentContainer.viewContext
            context.perform {
                // DO SOMETHING
                // try! context.save()
            }
        })

    }
    
    // MARK: Private
    private let persistentContainer: NSPersistentContainer
    
    // MARK: Properties (Static)
    static let shared = TimeService()
}
