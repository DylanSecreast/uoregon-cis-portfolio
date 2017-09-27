/*:
[Previous](@previous)

# Optional Types

Many programming languages express the concept of an absent value.  It is a very useful tool when reasoning about a value if it is possible that a state exists that isn't able to represented by a natural value of the type being considered.  Consider the concept of a backpack that contains a book; it is useful to store the value of the book in the backpack, but it is also possible you may want to store the fact that there is no book in the backpack.  In Swift an optional type is used to represent this concept, which is declared by appending a `?` character to any type.  This will allow you to use the `nil` value with that type:
*/
var integer: Int? = nil

var backpack: Book? = nil
backpack = Book(title: "Hello World", author: "Johnny Appleseed")

//: When dealing with with an optional type you cannot implicitly access the underlying value.  You must "unwrap" the value with the optional type to produce a value with a non-optional type.  This allows you to reason about nullability of values at compile time, rather than finding out about mistakes at run time.  You can use a special form of the `if` statement called an `if`-`let` statement to unwrap optional values safely:
if let someBook = backpack {
	let title = someBook.title
	print("There was a book in the backpack with the title \(title)")
}
else {
	print("The backpack was empty")
}

//: Alternatively if you do not need to handle the case where there is no value, you can use optional chaining syntax to access a property or method of the value if it exists.  If optional chaining is used to invoke a method and a nil value is encountered, the statement will stop executing.  If optional chaining results in a value, the result's type will always be an optional type:
let title = backpack?.title

//: Multiple optional values can be traversed in this manner:
let sequelTitle = backpack?.sequel()?.title

//: Optional chaining and `if`-`let` statements can be used to quickly traverse a graph of objects containing multiple optional types:
if let someSequelTitle = backpack?.sequel()?.title {
	print("There was a book and the title of its sequel is \(someSequelTitle)")
}
else {
	print("The backpack was empty, or the book in it had no sequel")
}

//: There occasionally arrises a situation where you as the programmer knows for a fact that a value will need to be absent, but that it will always be present when it is accessed (such as deferred loading of resources).  In this situation you can use the force unwrap `!` operator to unwrap an optional to produce its value.  If this operator is used on a value that is absent, the program will crash.  Only use this method if you are certain that you will never encounter a nil value at runtime:
backpack!.title

//: For such cases you can also consider declaring the type as an implicitly unwrapped optional instead of an optional using the `!` character appended to the type instead of the `?` character.  If this is done, the compiler will let you treat the value as if it were not an optional type.  This is only appropriate if you are certain that the value will never be absent when it is accessed, as the program will crash if a nil value is encountered:
var implicitlyUnwrappedBook: Book! = nil
implicitlyUnwrappedBook = Book(title: "Hello Optionals", author: "Johnny Appleseed")
implicitlyUnwrappedBook.title

//: [Next](@next)
