//
//  CatImagesViewController.swift
//  Assignment5
//

import CoreData
import UIKit


class CatImagesViewController : UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, NSFetchedResultsControllerDelegate {
	
    // MARK: UICollectionViewDataSource
	func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return fetchedResultsController.sections![section].numberOfObjects
	}

	func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let image = fetchedResultsController!.object(at: indexPath)
		let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "CatImageCell", for: indexPath) as! CatImageCell
        cell.update(forImageName: image.name!)
        
		return cell
	}
    
    // MARK: NSFetchedResultsControllerDelegate
    func controllerDidChangeContent(_ controller: NSFetchedResultsController<NSFetchRequestResult>) {
        catCollectionView.reloadData()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        fetchedResultsController = CatService.shared.images(for: selectedCat)
    }

	// MARK: Properties
	var categoryIndex: Int! = nil
    
    // MARK: Properties
    var selectedCat: Category! = nil
    
    // MARK: Properties (Private)
    var fetchedResultsController: NSFetchedResultsController<Image>!
    
    // MARK: Properties (IBOutlet)
    @IBOutlet private weak var catCollectionView: UITableView!
}
