//
//  Assignment6UITests.swift
//  Assignment6UITests
//


import XCTest


class Assignment6UITests: XCTestCase {
    override func setUp() {
        super.setUp()
        
        // Put setup code here. This method is called before the invocation of each test method in the class.
        
        // In UI tests it is usually best to stop immediately when a failure occurs.
        continueAfterFailure = false
        // UI tests must launch the application that they test. Doing this in setup will make sure it happens for each test method.
        XCUIApplication().launch()

        // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testCategoryTableCellCount() {
        XCTAssertGreaterThan(XCUIApplication().tables.cells.count, 0)
    }
    
    func testCatCollectionCellCount() {
        let app = XCUIApplication()
        let navBar = app.navigationBars["Cat Images"]
        let existsPredicate = NSPredicate (format: "exists == TRUE")
        
        // Test Burmese
        app.tables.staticTexts["Burmese"].tap()
        expectation(for: existsPredicate, evaluatedWith: navBar, handler: nil)
        waitForExpectations(timeout: 5.0, handler: nil)
        XCTAssertGreaterThan(app.collectionViews.images.count, 0)
        navBar.buttons["Categories"].tap()
        
        // Test Himalayan
        app.tables.staticTexts["Himalayan"].tap()
        expectation(for: existsPredicate, evaluatedWith: navBar, handler: nil)
        waitForExpectations(timeout: 5.0, handler: nil)
        XCTAssertGreaterThan(app.collectionViews.images.count, 0)
        navBar.buttons["Categories"].tap()
        
        // Test Ragdoll
        app.tables.staticTexts["Ragdoll"].tap()
        expectation(for: existsPredicate, evaluatedWith: navBar, handler: nil)
        waitForExpectations(timeout: 5.0, handler: nil)
        XCTAssertGreaterThan(app.collectionViews.images.count, 0)
        navBar.buttons["Categories"].tap()

        // Test Savannah
        app.tables.staticTexts["Savannah"].tap()
        expectation(for: existsPredicate, evaluatedWith: navBar, handler: nil)
        waitForExpectations(timeout: 5.0, handler: nil)
        XCTAssertGreaterThan(app.collectionViews.images.count, 0)
        navBar.buttons["Categories"].tap()
    
        // Test Scottish Fold
        app.tables.staticTexts["Scottish Fold"].tap()
        expectation(for: existsPredicate, evaluatedWith: navBar, handler: nil)
        waitForExpectations(timeout: 5.0, handler: nil)
        XCTAssertGreaterThan(app.collectionViews.images.count, 0)
        navBar.buttons["Categories"].tap()
    }

}
