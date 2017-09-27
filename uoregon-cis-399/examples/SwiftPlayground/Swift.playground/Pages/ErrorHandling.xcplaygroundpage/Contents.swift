/*:
[Previous](@previous)

# Error Handling

There are three main cases to consider when discussing error handling.

1. **Fatal** errors.  An error is a fatal error when the execution of a program cannot recover.  There are many fatal errors that a program can encounter; typical examples would include running out of memory, addressing invalid memory, disk based errors, etc.  When a fatal error is encountered, typically the result is a crash or alert dialog followed by the program halting execution.  One Swift specific example of a fatal error would be force unwrapping a nil optional value.
2. **Simple** errors.  An error is simple when it is recoverable and the fact that it has occurred is enough information.  If the process that generated the error returns a value, this type of error can typically be represented with an optional type for the return type and a nil value.  If no return value is necessary, adding a boolean return value to indicate success is typically sufficient.
3. **Complex** errors.  An error is a complex error when it is recoverable but additional information about the cause of the error is necessary.  One good example of this might be a failed HTTP request.  To recover from such an error it is important to know why the error happened.  In the event it was a connectivity issue the correct response might be to try again later.  If, on the other hand, it was a malformed request, other corrective action must be taken.

For the complex error case, Swift includes functionality for error propogation outside of the normal return value for a function.  A function can declare that it may cause such an error with the `throws` keyword.  An instance of any type that conforms to the `Error` protocol may be thrown from such a function:
*/
enum ExampleError: Error {
	case BadError
	case ReallyBadError
	case YetAnotherError
}

func complexErrorFunction() throws {
	throw ExampleError.BadError
}

//: If a function is marked with `throws`, additional work is necessary to invoke the function and handle any `ErrorType` that is thrown as a result.  First, the `try` keyword is required before the invocation of the method that is marked `throws`.
try complexErrorFunction()

//: Additionally, a method that invokes a `throws` method must either also be marked as `throws`, or it must handle the potential error by wrapping the `throws` method invocation in a `do`-`catch` block.  Just like a switch statement's cases, the `catch` blocks must be exhaustive:
func foo() {
	do {
		try complexErrorFunction()

		print("No error!")
	}
	catch ExampleError.BadError {
		print("BadError!")
	}
	catch ExampleError.ReallyBadError {
		print("ReallyBadError!")
	}
	catch ExampleError.YetAnotherError {
		print("YetAnotherError!")
	}
	catch _ {
		print("Unexpected error caught")
	}
}

//: Alternatively it is possible to supress an error and instead convert the result the throws function into a nil value using the `try?` keyword.  This will alter the type returned by the `throws` function to make it an optional type.  If the `throws` function does not return a value at all, then the error is ignored.
try? complexErrorFunction()

//: In the case that the programmer is certain no error will be thrown, the `throws` method can be invoked with the `try!` keyword.  Just as is the case with other uses of ! (aside from boolean logic), if an error is thrown the program will crash (except for in playgrounds, apparently).
try! complexErrorFunction()

//: [Next](@next)
