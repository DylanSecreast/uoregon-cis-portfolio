/*:
[Previous](@previous)

# Tuples

A tuple is a grouping of multiple values of any type into a single compound value.
*/
let someTuple: (Int, String, Float) = (6, "Hello World", 3.14)

//: The values stored in a tuple can be accessed via implicit index properties, starting at 0:
let someInt: Int = someTuple.0
let someString: String = someTuple.1
let someFloat: Float = someTuple.2

//: In some cases it may be desirable to have named values in a tuple to improve readability or make accessing specific values easier.  This can be done by assigning labels to the tupel values:
let colorValues: (red: UInt8, green: UInt8, blue: UInt8) = (255, 0, 0)
colorValues.red
colorValues.green
colorValues.blue

//: Alternatively you can use decomposition to assign values stored in the tuple to new constants or variables.  Using this technique multiple tuple values can be assigned at once.  Note that the `_` character serves as a token indicating the value should be ignored:
let (someDecomposedInt, _, _) = someTuple
someDecomposedInt
let (_, someDecomposedString, someDecomposedFloat) = someTuple
someDecomposedString
someDecomposedFloat

//: [Next](@next)
