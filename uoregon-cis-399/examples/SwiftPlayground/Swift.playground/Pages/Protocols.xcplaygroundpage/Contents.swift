/*:
[Previous](@previous)

# Protocols

Protocols provide a type based mechanism by which a class, struct, or enum can conform to a contract (and in the case of classes, they also provide a safer alternative to multiple inheritence).  The contract provided by a protocol is in the form of required methods, properties, and/or initializers:
*/
protocol SomeProtocol {
	func requiredMethodThatHandles(a parameter: String) -> Void

	var readWriteProperty: Int { get set }
	var readOnlyProperty: Int { get }

	init(value: Int)
}

//: When conforming to a protocol, all of the requirements must be met:
class SomeClass { }
class SomeChildClass: SomeClass, SomeProtocol {
	func requiredMethodThatHandles(a parameter: String) {
		print("Hello " + parameter)
	}

	required init(value: Int) {
		readWriteProperty = value
	}

	var readWriteProperty = 0
	var readOnlyProperty: Int {
		get {
			return readWriteProperty * 2
		}
	}
}

func foo(_ instance: SomeProtocol) {
	instance.requiredMethodThatHandles(a: "World")
}
let someChildClassInstance = SomeChildClass(value: 5)
foo(someChildClassInstance)

//: [Next](@next)
