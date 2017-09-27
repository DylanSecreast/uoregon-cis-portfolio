/*:
[Previous](@previous)

# Closures

A closure is a self contained segment of code that can be stored and passed around like any other value (otherwise known as a Block in Objective-C, or a lambda in various other languages).  Functions are generally just a named form of a closure.  The other common form that closure take on is in the form of an unnamed piece of code that is written with syntax that is more brief than a typical function.  A closure is one or more statements inside `{}` characters, optionally taking parameters and having a return type that are separated from the body of the closure by the `in` keyword:
*/
let someClosure = { () -> Void in
	print("Hello World")
}
someClosure()

let someOtherClosure = { (value: String) -> String in
	return "Hello " + value
}
someOtherClosure("Closures")

//: Closure in Swift can "close over" or capture variables in the lexical scope in which they are defined:
let prefix = "Hello"
let anotherClosure = { (value: String) -> String in
	return prefix + " " + value
}
anotherClosure("Closures")
anotherClosure("Capturing")

//: Closures are useful in situations where a function takes another function as a parameter, such as the sort function on the `Array` type:
var array = ["The", "Quick", "Brown", "Fox", "Jumped", "Over", "The", "Lazy", "Dog"]
array = array.sorted(by: { (valueOne: String, valueTwo: String) -> Bool in
	return valueOne < valueTwo
})

//: In the case where a function's last parameter is a closure, there is a more brief form of closure syntax called "Trailing Closure Syntax", which can be used to further shorten your code.  In the shortest form, the parameter list is omitted and implicit parameter names are used ($0 - $n) whose types are inferred based on the method signature of the parameter being called.  The return type is also inferred based on the method signature of the parameter being called.  Additionally, the closure is placed outside of the parameter list of the message being called and the parameter name is omitted (in the case where it is the only parameter, the parenthesis can also be omitted).  Lastly, if the closure is a single line and is inferred to have a return type that is non-`Void`, the `return` keyword is implied.  This is equivalent to the previous example:
array = array.sorted { $0 < $1 }
array

//: [Next](@next)
