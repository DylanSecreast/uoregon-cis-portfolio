//
//  CategoryListViewController.swift
//  Assignment4
//
//  Created by Dylan Secreast on 2/5/17.
//
//

import UIKit


class CategoryListViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return CatService.shared.catCategories().count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "CategoryCell", for: indexPath)
        cell.textLabel?.text = CatService.shared.catCategories()[indexPath.row].title
        cell.detailTextLabel?.text = CatService.shared.catCategories()[indexPath.row].subtitle
        return cell
    }
    
    // MARK: View Management
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "CatSegue" {
            // Configure the destination view controller with information about what was selected so it can show
            // appropriate details.
//            let catImagesViewController = segue.destination as! CatImagesViewController
//            let indexPath = catImagesView.indexPathForSelectedRow!
//            catImagesView.selectRow(at: nil, animated: true, scrollPosition: .none)
//            catImagesViewController.catImagesView = CatService.shared.catCategories()[indexPath.row]
        }
        else {
            // If the segue has an identifier that is unknown to this view controller, pass it to super.
            super.prepare(for: segue, sender: sender)
        }
    }
    
    // MARK: Properties (IBOutlet)
    @IBOutlet private weak var catImagesView: UITableView!
    
}
