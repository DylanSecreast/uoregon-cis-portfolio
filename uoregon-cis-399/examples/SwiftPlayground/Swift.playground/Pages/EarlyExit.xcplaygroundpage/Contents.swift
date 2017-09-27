/*: [Previous](@previous)

# Early Exit

A `guard` statement is used to perform validation or optional binding that must succeed in order for the function to continue.  Like an `if` statement, a `guard` statement checks conditions or performs optional bindings.  Unlike an `if` statement, there is always an `else` block of code that is required to transfer control to exit the block of code in which the `guard` statement appears (i.e., `return` or `throw` in a function, `continue` or `break` in a loop, etc.):
*/
func process(_ response: String, withStatus status: Int) -> Bool {
	guard status >= 200 && status < 300 else {
		print("Error response")

		return false
	}

	print("Successful response")

	return true
}
process("Unauthorized Response", withStatus: 401)
process("Successful Response", withStatus: 200)

func countCats(in animals: [String]?) -> Int {
	guard let someAnimals = animals else {
		return 0
	}

	var count = 0
	for animal in someAnimals {
		guard animal == "Cat" else {
			continue
		}

		count += 1
	}

	return count
}
countCats(in: nil)
countCats(in: ["Cat", "Cat", "Goose"])

//: One typical issue that arises with exiting early is handling the cleanup of any resources that are being used prior to exiting (closing an input stream, releasing resources, etc.).  Swift provides a mechanism for such cleanup so that it can be specified in a single place.  This is done with a `defer` statement, which ensures that a particular block of code will always be run prior to exit:
import Foundation

func handleConnection(inputStream: InputStream) throws -> NSData {
	inputStream.open()
	defer {
		inputStream.close()
	}

	let data = NSMutableData()
	var buffer = Array<UInt8>(repeating: 0, count: 1024)
	while inputStream.hasBytesAvailable {
		let readByteCount = inputStream.read(&buffer, maxLength: buffer.count)
		guard readByteCount != -1 else {
			throw NSError(domain: "edu.uoregon.cs.cis399", code: 0, userInfo: nil)

			// The defer block executes here prior to propogation of the thrown error
		}

		data.append(&buffer, length: buffer.count)
	}

	return data

	// The defer block executes here prior to the return from the method
}

//: Note: If multiple defer blocks are present, they will be executed in reverse order that they appear in (i.e., the ones latest in the code block being exited will occur first).

//: [Next](@next)
