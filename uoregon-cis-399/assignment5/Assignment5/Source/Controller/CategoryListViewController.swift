//
//  CategoryListViewController.swift
//  Assignment5
//

import CoreData
import UIKit


class CategoryListViewController : UIViewController, UISearchBarDelegate, UITableViewDataSource, UITableViewDelegate, NSFetchedResultsControllerDelegate {
    
	// MARK: UISearchBarDeleate
	func searchBarCancelButtonClicked(_ searchBar: UISearchBar) {
		view.endEditing(true)
	}
    
    // MARK: UITableViewDataSource
    func numberOfSections(in tableView: UITableView) -> Int {
        return catFetchedResultsController.sections?.count ?? 0
    }

	func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return catFetchedResultsController.sections![section].numberOfObjects
	}

	func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
		let cell = tableView.dequeueReusableCell(withIdentifier: "CatCell", for: indexPath)
        let catValues = catFetchedResultsController.object(at: indexPath)
		cell.textLabel?.text = catValues.title
		cell.detailTextLabel?.text = "Contains " + " images" //"Row \(indexPath.row) lol" //catValues.subtitle

		return cell
	}
    
    // MARK: NSFetchedResultsControllerDelegate
    func controllerDidChangeContent(_ controller: NSFetchedResultsController<NSFetchRequestResult>) {
        catListTable.reloadData()
    }

	// MARK: View Management
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)

		`.append(NotificationCenter.default.addObserver(forName: .UIKeyboardWillShow, object: nil, queue: OperationQueue.main, using: { [unowned self] (notification) in
			self.catListTable.adjustInsets(forWillShowKeyboardNotification: notification)
		}))

		observerTokens.append(NotificationCenter.default.addObserver(forName: .UIKeyboardWillHide, object: nil, queue: OperationQueue.main, using: { [unowned self] (notification) in
			self.catListTable.adjustInsets(forWillHideKeyboardNotification: notification)
		}))
	}

	override func viewDidDisappear(_ animated: Bool) {
		super.viewDidDisappear(animated)

		for observerToken in observerTokens {
			NotificationCenter.default.removeObserver(observerToken)
		}
	}

	override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
		if segue.identifier == "CatImagesSegue" {
			let catImagesViewController = segue.destination as! CatImagesViewController

			let selectedIndexPath = catListTable.indexPathForSelectedRow!
			catImagesViewController.categoryIndex = selectedIndexPath.row

            catImagesViewController.selectedCat = catFetchedResultsController?.object(at: selectedIndexPath)
            
			catListTable.deselectRow(at: selectedIndexPath, animated: true)
		}
		else {
			super.prepare(for: segue, sender: sender)
		}
	}
    
    override func viewDidLoad() {
        super.viewDidLoad()
        catFetchedResultsController = CatService.shared.catCategories()
        catFetchedResultsController.delegate = self
    }

	// MARK: Properties (Private)
	private var observerTokens = Array<Any>()
    
    // MARK: Properties (Private)
    private var catFetchedResultsController: NSFetchedResultsController<Category>!

	// MARK: Properties (IBOutlet)
	@IBOutlet private weak var catListTable: UITableView!
}
