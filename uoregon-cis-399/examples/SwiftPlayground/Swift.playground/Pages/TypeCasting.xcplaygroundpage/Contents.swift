/*:
[Previous](@previous)

# Type Casting

Type casting is used to test whether or not a particular instance is of a particular type.  This is useful when type information is limited (as is the case when processing JSON data, for example) or you wish to handle specific types differently from the more general type that is known.

To check a type the `is` operator is employed:
*/
let array: [Any] = [1, "Hello", 3.14159]
for instance in array {
	if instance is String {
		print("The instance is a String")
	}
	else {
		print("The instance is not a String")
	}
}

//: There are multiple ways to cast an instance to a type if you need to access type specific functionality of the instance.  The `as?` keyword can be used to safely cast an instance to a type, but it produces an optional version of that type to allow for a nil value if the cast fails.  This can be combined with any method of unwrapping optionals to access the instance:
for instance in array {
	let maybeString = instance as? String // The type of maybeString is String?
	if let someString = maybeString {
		print("The instance is a String with the value " + someString)
	}
	else {
		print("The instance is not a String")
	}
}

//: Sometimes it is the case that the programmer knows for a fact that an instance is a particular type.  In this case the `as!` keyword can be used to force cast the instance to that type directly without producing an optional.  If the instance is not the type it is being cast to, the program will crash:
let definitelyString = array[1] as! String // The type of definitelyString is String
print("Fact: array[1] contains a String with the value " + definitelyString)

//: Alternatively `case` statements in a `switch` statement can specify the type of an instance as part of their condition using the `as` or `is` keywords:
for instance in array {
	switch instance {
	case let someString as String:
		print("The instance is a String with the value " + someString)
	case is Int:
		print("The instance is an Int")
	default:
		print("The instance is not a String or an Int")
	}
}
