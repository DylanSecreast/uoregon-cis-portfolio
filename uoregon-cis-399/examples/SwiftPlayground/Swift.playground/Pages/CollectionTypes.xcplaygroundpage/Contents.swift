/*:
[Previous](@previous)

# Collection Types

The Swift standard library provides `Array`, `Dictionary`, and `Set` collection type.  Additionally, the language includes support for `Array` and `Dictionary` literals.  Sets can also be declared with a literal statement, but not in conjunction with type inference (i.e., you must be using the literal somewhere a `Set` is expected for it to be considered a `Set`).
*/
let arrayOfStrings: Array<String> = ["Hello", "World"]
let dictionaryOfStringsToInts: Dictionary<String, Int> = ["Hello" : 1, "World" : 2]
let setOfStrings: Set<String> = ["Hello", "Hello", "World"]

//: The `Array` and `Dictionary` types both support an alternative type form of declaration that is generally used for brevity:
let equivalentArrayOfStrings: [String] = ["Hello", "World"]
let equivalentDictionaryOfStringsToInts: [String : Int] = ["Hello" : 1, "World" : 2]

//: Collections can contain any type, but are strongly typed (i.e., Generics are supported).  The types in the declaration in the example above are not necessary, as the Type Interence system could have inferred them based on the initial assignment.  If a more lax type is desired than what is inferred from the initial assignment, the type must be written explicitly
let laxTypeArray: [Any] = ["Hello", "Any"] // Results in a type of [Any]
let strictInferredTypeArray = ["Hello", "Any"] // Results in a type of [String]

//: Subscript syntax and slicing is also supported:
var array = ["The", "Quick", "Brown", "Fox", "Jumped", "Over", "The", "Lazy", "Dog"]
let string = array[3]
let subArrayOne = array[1..<4]
let subArrayTwo = array[6...8]

array[2] = "Red"
array

//: [Next](@next)
