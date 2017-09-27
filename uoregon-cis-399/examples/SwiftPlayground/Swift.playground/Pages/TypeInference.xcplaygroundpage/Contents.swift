/*:
[Previous](@previous)

# Type Inference

Swift is a strongly typed language, so a type is always required.  However, Swift also has a strong *Type Inference* system.  This often allows the compiler to infer a type when it is contextually possible.

This constant has an explicit type of `String`:
*/
let explicitStringConstant: String = "Hello World"

//: This constant has no type listed, but the compiler infers the type `String` based on the initial value assignment
let inferredStringConstant = "Hello Inferred World"

//: [Next](@next)
