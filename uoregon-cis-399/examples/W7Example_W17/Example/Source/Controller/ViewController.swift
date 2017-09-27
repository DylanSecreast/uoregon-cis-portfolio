//
//  ViewController.swift
//  Example
//
//  Created by Charles Augustine on 2/22/17.
//  Copyright © 2017 Charles. All rights reserved.
//


import UIKit


class ViewController: UIViewController {
	// MARK: IBAction
	@IBAction private func triangleViewTapped(sender: UITapGestureRecognizer) {
		// Call the updateTriangleColors method in response to a tap gesture
		triangleView.updateTriangleColors()
	}

	@IBAction private func triangleViewRotated(sender: UIRotationGestureRecognizer) {
		// Add the gesture recognizer's rotation to the current triangleView rotation value
		triangleView.rotation = triangleView.rotation + sender.rotation

		// Reset the gesture recognizer rotation to zero.  If this is not set to zero, the value will accumulate
		sender.rotation = 0
	}

	// MARK: Properties (IBOutlet)
	@IBOutlet private weak var triangleView: TriangleView!
}

