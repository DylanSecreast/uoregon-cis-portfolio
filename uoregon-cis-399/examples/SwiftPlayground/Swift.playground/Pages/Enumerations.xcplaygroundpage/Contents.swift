/*:
[Previous](@previous)

# Enumerations

An enumeration stores a collection of related constants and defines a type that can be used when one of those constants is desired.  Like structures they adhere to "pass by value" semantics and are able to contain various types of properties, methods, and initializers.  They are declared with the `enum` keyword, and each constant is declared with the `case` keyword.
*/
enum Shape {
	case Circle
	case Square
	case Triangle

	var name: String {
		get {
			let result: String
			switch self {
			case .Circle:
				result = "Circle"
			case .Square:
				result = "Square"
			case .Triangle:
				result = "Triangle"
			}

			return result
		}
	}
}

func printName(of shape: Shape) {
	print(shape.name)
}

printName(of: Shape.Triangle)
printName(of: .Circle)

//: Enumerations can also have associated values of any type:
enum Literature {
	case Magazine(name: String, volume: Int)
	case Book(title: String, author: String)
}

let magazineInstance = Literature.Magazine(name: "Wired", volume: 50) // This statement uses type inference
let bookInstance: Literature = .Book(title: "Lord of the Rings", author: "J.R.R. Tolkein") // This statement does not use type inference

//: Enumerations can also be related to a "raw type", which can be useful for converting String or other value based constants (that are retrieved from a database or webservice, for example) into a more type safe form.  Note that enum instances that have a raw type can be constructed from the raw value, but such a construction results in an optional type because an unmapped value will produce a nil result:
enum GradeRecordType: Int {
	case Assignment = 0
	case Exam = 1
	case Project = 2
}

let recordTypeValue = 1
let recordType = GradeRecordType(rawValue: recordTypeValue)
if let someRecordType = recordType {
	print("Record type found for record type value \(recordTypeValue)")
}
else {
	print("No record type found for record type value \(recordTypeValue)")
}

//: [Next](@next)
