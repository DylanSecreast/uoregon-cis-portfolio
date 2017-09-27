//
//  CatService.swift
//  Assignment5
//


import CoreData


class CatService {
    
    // MARK: Data Access
    func catCategories() -> NSFetchedResultsController<Category> {
        let fetchRequest: NSFetchRequest<Category> = Category.fetchRequest()
        fetchRequest.sortDescriptors = [NSSortDescriptor(key: "title", ascending: true)]
        
        return fetchedResultsController(for: fetchRequest)
    }
    
    func images(for category: Category) -> NSFetchedResultsController<Image> {
        let fetchRequest: NSFetchRequest<Image> = Image.fetchRequest()
        fetchRequest.predicate = NSPredicate(format: "category == %@", category)
        fetchRequest.sortDescriptors = [NSSortDescriptor(key: "orderIndex", ascending: true)]
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
		persistentContainer = NSPersistentContainer(name: "Model")
		persistentContainer.loadPersistentStores(completionHandler: { (storeDescription, error) in
            let context = self.persistentContainer.viewContext
            context.perform {
                let categoryFetchRequest: NSFetchRequest<Category> = Category.fetchRequest()
                let count = try! context.count(for: categoryFetchRequest)
                
                guard count == 0 else {
                    return
                }
                
                let catDataPath = Bundle.main.path(forResource: "CatData", ofType: "plist")!
                let catData = NSArray(contentsOfFile: catDataPath) as! Array<Dictionary<String, AnyObject>>
                
                for catValues in catData {
                    let category = Category(context: context)
                    let title = catValues["CategoryTitle"] as! String
                    category.title = title
                    
                    let imageValues = catValues["ImageNames"] as! Array<String>
                    for enumImageValues in imageValues.enumerated() {
                        let image = Image(context: context)
                        image.name = enumImageValues.element
                        image.orderIndex = Int32(enumImageValues.offset)
                        image.category = category
                    }
                }
               
                try! context.save()
            }
		})
	}
    
	// MARK: Private
	private let persistentContainer: NSPersistentContainer

	// MARK: Properties (Static)
	static let shared = CatService()
}
