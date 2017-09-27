/*:
[Previous](@previous)

# Functions

Functions are declared using the `func` keyword.  Functions in Swift have named parameters:
*/
func doSomething(withParameter parameter: String, andOtherParameter otherParameter: String) {
	print(parameter + " " + otherParameter)
}

doSomething(withParameter: "Hello", andOtherParameter: "World")

//: A return type can be specified by appending it after the parameter list, prefixed with `->`.  A function that returns nothing can specify a return type of `Void` or the empty tuple type `()` to be explicit:
func messageToPrint() -> String {
	return "Hello World"
}

print(messageToPrint())

func functionThatReturnsNothing() -> Void {}

//: It is possible to specify a default value for a parameter and omit that parameter entirely when calling the function.  If multiple parameters have default values any permutation of them may be omitted:
func createDoubleString(from string: String, printResults: Bool = true) -> String {
	let result = string + string

	if printResults {
		print(result)
	}

	return result
}

createDoubleString(from: "Foo")
createDoubleString(from: "Foo", printResults: false)

//: Multiple values can be returned from a function using a tuple return type:
func colorValues() -> (red: Float, green: Float, blue: Float) {
	return (255.0, 0.0, 0.0)
}

let (redValue, greenValue, _) = colorValues()
redValue
greenValue

//: Functions in Swift are considered normal types and can be used just like any other type.  For example, a variable can have a function type and have a function assigned to it, a function's parameter can have a function type, or a function's return type can be another function:
let someFunction = messageToPrint
print(someFunction())

func appendHello(toResultOf function: () -> String) {
	print("Hello " + function())
}
appendHello(toResultOf: messageToPrint)

func foo() -> () -> String {
	return messageToPrint
}
foo()()

//: [Next](@next)
