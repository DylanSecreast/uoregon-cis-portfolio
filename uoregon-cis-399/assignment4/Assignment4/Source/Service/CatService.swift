//
//  CatService.swift
//  Assignment4
//


import Foundation


class CatService {
	// MARK: Service
	func catCategories() -> Array<(title: String, subtitle: String)> {
        var title = ""
        var subtitle = ""
        var returnArray = Array<(title: String, subtitle: String)>()
        var numImages = 0
        
        for cat in catData {
            if let catTitle = cat["CategoryTitle"] {
                title = catTitle as! String
                numImages = (cat["ImageNames"]?.count)!
                subtitle = "Contains " + "\(numImages)" + " images"
            }
            else {
                title = "Unknown"
                subtitle = "--"
            }
            returnArray.append((title, subtitle))
        }
        
        return returnArray
	}

	func imageNamesForCategory(atIndex index: NSInteger) -> Array<String> {
        
        //		var filteredFruitData: Array<Dictionary<String, Any>>
        //		for fruitValues in fruitData {
        //			if fruitValues["FruitName"] == fruitName {
        //				filteredFruitData.append(fruitValues)
        //			}
        //		}
        //
        //		let result: Array<String>
        //		if filteredFruitData.count > 0 {
        //			let fruitValues = filteredFruitData[0]
        //			if let taxonomyValues = fruitValues["FruitTaxonomy"] as? Array<String> {
        //				result = taxonomyValues
        //			}
        //			else {
        //				result = []
        //			}
        //		}
        //		else {
        //			result = []
        //		}
        //
        //		return result
        
//        var returnArray = Array<String>()
        
        
        
        
//        return returnArray
        
		// TODO: Remove the fatalError call and return the array of image names for the cat category specified by the index
		fatalError("imageNamesForCategory(atIndex:) not implemented")
	}

	// MARK: Initialization
	private init() {
		let catDataPath = Bundle.main.path(forResource: "CatData", ofType: "plist")!
		catData = NSArray(contentsOfFile: catDataPath) as! Array<Dictionary<String, AnyObject>>
	}

	// MARK: Properties (Private)
	private let catData: Array<Dictionary<String, AnyObject>>

	// MARK: Properties (Static)
	static let shared = CatService()
}
