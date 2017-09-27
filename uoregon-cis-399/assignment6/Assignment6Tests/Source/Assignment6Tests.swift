//
//  Assignment6Tests.swift
//  Assignment6Tests
//

import UIKit
import XCTest
@testable import Assignment6

class Assignment6Tests: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testCategoryCount() {
        // Test category count
        XCTAssertGreaterThan(CatService().catCategories().sections!.count, 0)
        
        // Test category section count
        for cat in CatService().catCategories().sections!.enumerated() {
            XCTAssertGreaterThan(cat.element.numberOfObjects, 0)
        }
    }
    
    func testImageCount() {
        let catService = CatService()
        let catCategories = catService.catCategories()
        var i = 0
        
        for _ in catCategories.sections! {
            let indexPath = IndexPath(row: i, section: 0)
            let currentCat = catCategories.object(at: indexPath)
            let catImages = catService.images(for: currentCat)
            XCTAssertGreaterThan(catImages.fetchedObjects!.count, 0)
            i = i + 1
        }
    }
    
}
