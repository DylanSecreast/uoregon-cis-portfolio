//
//  TriangleView.swift
//  Example
//


import UIKit


@IBDesignable class TriangleView : UIView {
	// MARK: Configuration
	func updateTriangleColors() {
		var colors = possibleColors

		// Update the triangle values with colors randomly chosen from the possible colors set
		for index in 0..<allTriangleValues.count {
			let randomColorIndex = Int(arc4random_uniform(UInt32(colors.count)))
			allTriangleValues[index].1 = colors[randomColorIndex]
			colors.remove(at: randomColorIndex)
		}

		// This must be called for the view to be redrawn
		setNeedsDisplay()
	}

	// MARK: UIView
	override func draw(_ rect: CGRect) {
		// The CGContext returned by UIGraphicsGetCurrentContext() is setup by the system prior to this method being
		// invoked.  Check to make sure it is not nil, which would happen if this method were called manually.
		guard let context = UIGraphicsGetCurrentContext() else {
			return
		}

		// Loop through allTriangleValues and draw each triangle
		for triangleValues in allTriangleValues {
			// The saveGState function stores the current graphical state on a stack
			context.saveGState()

			// By default just calling rotate will rotate the drawing around the origin, which is the top left of the
			// screen.  In order to rotate around the center we must translate to the center, then rotate.  Then we must
			// translate back to the upper left in order for the drawing origin to be correct.
			let centerX = rect.width / 2.0
			let centerY = rect.height / 2.0
			context.translateBy(x: centerX, y: centerY)
			context.rotate(by: rotation * triangleValues.multiplier)
			context.translateBy(x: -centerX, y: -centerY)

			// Call the helper function that creates a path for the triangle
			context.addPath(pathForTriangle(withMultiplier: triangleValues.multiplier, in: rect))

			// Set the fill color as appropriate
			context.setFillColor(triangleValues.color)

			// Fill the current path
			context.drawPath(using: .fill)

			// Calling restoreGState pops the newest saved state made by calling saveGState and resets the context to
			// that state
			context.restoreGState()
		}
	}

	// MARK: Private
	private func pathForTriangle(withMultiplier multiplier: CGFloat, in rect: CGRect) -> CGPath {
		// Do some fiddly math to create the correct coordinates for the triangle corners
		let topCornerX = rect.width / 2.0
		let topCornerY = (rect.height * (1.0 - multiplier)) / 2.0

		let halfWidth = (rect.width * (1.0 - multiplier)) / 2.0
		let lowerRightCornerX = rect.width - halfWidth
		let lowerRightCornerY = rect.height - topCornerY

		let lowerLeftCornerX = halfWidth
		let lowerLeftCornerY = lowerRightCornerY

		// Construct a path, first moving to the top corner, then adding lines to the lower right and lower left
		// corners.  Calling closeSubpath will add a line from the current position to the start position.
		let path = CGMutablePath()
		path.move(to: CGPoint(x: topCornerX, y: topCornerY))
		path.addLine(to: CGPoint(x: lowerRightCornerX, y: lowerRightCornerY))
		path.addLine(to: CGPoint(x: lowerLeftCornerX, y: lowerLeftCornerY))
		path.closeSubpath()

		return path
	}

//	// These methods are used to implement gesture handling when using UIResponder methods.  All must be implemented and
//	// should not call super.  The code below could be used to handle taps instead of the UITapGestureRecognizer that
//	// is configured in the storyboard.
//	override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
//		// Intentionally left blank
//	}
//
//	override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
//		updateTriangleColors()
//	}
//
//	override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
//		// Intentionally left blank
//	}
//
//	override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
//		// Intentionally left blank
//	}

	// MARK: Properties
	var rotation = CGFloat(0.0) {
		didSet {
			// This property can be set from an external source (such as a view controller).  Since the drawing should
			// change in response to this, we must call setNeedsDisplay in the didSet handler to update the view as
			// expected.
			setNeedsDisplay()
		}
	}

	// MARK: Properties (Private)
	private var allTriangleValues: Array<(multiplier: CGFloat, color: CGColor)> = [(CGFloat(1.0), UIColor.red.cgColor), (CGFloat(0.66), UIColor.blue.cgColor), (CGFloat(0.33), UIColor.green.cgColor)]

	// MARK: Properties (Private Constant)
	private let possibleColors = [UIColor.red.cgColor, UIColor.green.cgColor, UIColor.blue.cgColor, UIColor.purple.cgColor, UIColor.black.cgColor]
}
