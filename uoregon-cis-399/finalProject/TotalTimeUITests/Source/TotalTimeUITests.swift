//
//  TotalTimeUITests.swift
//  TotalTimeUITests
//
//  Created by Dylan Secreast on 2/28/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
//

import XCTest

class TotalTimeUITests: XCTestCase {
        
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
    
    // Verify UITab navigation works
    func testUINavigation() {
        let tabBarsQuery = XCUIApplication().tabBars
        tabBarsQuery.buttons["Job"].tap()
        tabBarsQuery.buttons["History"].tap()
        tabBarsQuery.buttons["Done"].tap()
        tabBarsQuery.buttons["Home"].tap()
    }
    
    // Verify user has inputed the necessary info before starting timer
    func testInput() {
        let app = XCUIApplication()
        app.tabBars.buttons["Job"].tap()
        
        app.textFields["My New Job"].tap()
        app.textFields["My New Job"].typeText("My New Job")
        
        app.textFields["XX.XX"].tap()
        app.textFields["XX.XX"].typeText("28.75")
        
        app.textFields["Bob Bogus"].tap()
        app.textFields["Bob Bogus"].typeText("")
        
        app.textFields["555-555-5555"].tap()
        app.textFields["555-555-5555"].typeText("")
        
        app.textFields["email@domain.com"].tap()
        app.textFields["mail@domain.com"].typeText("")
        
        app.buttons["Save"].tap()
        
        app.alerts["Saved!"].buttons["OK"].tap()
        
    }
    
}
