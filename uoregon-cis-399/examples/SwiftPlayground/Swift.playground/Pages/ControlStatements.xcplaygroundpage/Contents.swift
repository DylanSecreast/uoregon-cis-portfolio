/*:
[Previous](@previous)

# Control Statements

Swift supports the normal set of control statements common to most programming languages.

`while` loops to iterate until a condition is met that is evaluated prior to looping:
*/
var whileIndex = 0
while whileIndex < 10 {
	print("The index is \(whileIndex)")

	whileIndex += 1
}

//: `repeat`-`while` to iterate until a condition is met that is evaluated after looping (this is often a do/while loop in other languages):
var repeatIndex = 0
repeat {
	print("The index is \(repeatIndex)")

	repeatIndex += 1
} while repeatIndex < 10

//: `for`-`in` loops to iterate a collection:
let words = ["Hello", "World"]
for word in words {
	print(word)
}

//: 'if' statements to control flow conditionally:
let a = 5
if a <= 5 {
	print("The value of a is less than or equal to 5")
}
else {
	print("The value of a is not less than or equal to 5")
}

//: `switch` statements to control flow of execution conditionally:
switch a {
case 0:
	print("The value of a is 0")
case 1, 2, 3:
	print("The value of a is 1, 2, or 3")
case 4...6:
	print("The value of a is between 4 and 6 [4, 6]")
case 7..<11:
	print("The value of a is between 7 and 10 [7, 11)")
default:
	print("The value of a is not a special case")
}

//: [Next](@next)
