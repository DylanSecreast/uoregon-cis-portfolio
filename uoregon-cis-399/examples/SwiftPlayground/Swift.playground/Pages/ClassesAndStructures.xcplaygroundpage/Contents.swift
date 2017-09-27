/*:
[Previous](@previous)

# Classes and Structures

Classes are defined with the `class` keyword.  They can contain properties (constants, variables, and computed values), nested functions, initializers, deinitializers, and other nested types.  All properties must have an initial value specified, be optional (in which case the initial value is `nil`), or be initialized in a provided initializer.  Variable properties can also provide code to be executed prior to and after the value is set:
*/
class SomeClass {
	func doSomethingInteresting() {
		print("Hello World")
	}

	init() {
		anotherInstanceConstant = "Constant2"
	}

	init(value: String) {
		anotherInstanceConstant = value
	}

	let instanceConstant = "Constant"
	let anotherInstanceConstant: String
	var instanceVariable = "Variable" {
		willSet {
			print("About to change the value to \(newValue)")
		}
		didSet {
			print("Replaced the old value \(oldValue)")
		}
	}
	var instanceComputedValue: String {
		get {
			return instanceConstant + " " + instanceVariable
		}
	}
}

let instanceOne = SomeClass()
let instanceTwo = SomeClass(value: "AnotherConstant")

instanceOne.anotherInstanceConstant
instanceTwo.anotherInstanceConstant

instanceOne.instanceVariable = "NewVariable"
instanceOne.instanceComputedValue
instanceOne.doSomethingInteresting()

//: Classes can also participate in inheritance via subclassing.  Such subclasses can use the `override` keyword to provide a new implementation of a function that provides alternative or specialized behavior, unless the function was declared with the `final` keyword:
class SomeChildClass: SomeClass {
	override func doSomethingInteresting() {
		print("Hello Child")
	}
}

//: Class instances adhere to "pass by reference" semantics.  This means that multiple variables or constants may point to a single reference of a class:
let anotherInstanceOneReference = instanceOne
instanceOne.instanceVariable
anotherInstanceOneReference.instanceVariable = "Change"
instanceOne.instanceVariable

//: Structures are defined with the 'struct' keyword.  A structure is similar to a class except that it cannot participate in inheritance, must explicitly declare methods that mutate properties as `mutating`, and that it adheres to "pass by value" semantics.  This means that a struct is effectively copied* when it is assigned or passed as a parameter:
struct SomeStruct {
	var instanceVariable = "Initial"
}

let instanceThree = SomeStruct()
instanceThree.instanceVariable
var instanceFour = instanceThree
instanceFour.instanceVariable = "New"
instanceFour.instanceVariable
instanceThree.instanceVariable

/*:
It is worth noting that most of the types defined in the Swift standard library (such as `String`, `Array`, `Dictionary`, and `Set`) are structs, and follow value semantics.

[Next](@next)
*/
