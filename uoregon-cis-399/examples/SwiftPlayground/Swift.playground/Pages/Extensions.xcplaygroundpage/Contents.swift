/*:
[Previous](@previous)

# Extensions

An extension can be used to add new functionality to an existing type, regardless of whether or not the source code for those types is available.  An extension can add new methods, computed properties, initializers, and declare conformance to protocols:
*/
protocol Excitable {
	mutating func becomeExcited()

	var isExcited: Bool { get }
}

extension String: Excitable {
	mutating func becomeExcited() {
		self += "!!!"
	}

	var isExcited: Bool {
		get {
			return hasSuffix("!!!")
		}
	}
}

var stringValue = "Hello World"
stringValue.isExcited
stringValue.becomeExcited()
stringValue.isExcited

func getThisPartyStarted(participant: inout Excitable) {
	if !participant.isExcited {
		participant.becomeExcited()
	}
}
var anotherStringValue: Excitable = "ReadyToRock"
getThisPartyStarted(participant: &anotherStringValue)

//: In addition to concrete types (classes, structs, enums), an extension can also be written for protocols.  An extension to a protocol can provide default method implementations for methods declared in the protocol or it can add additional methods that will be available to any type conforming to the protocol.  If a default implementation is provided it will only be used for conforming types that do not provide an implementation of their own:
extension Excitable {
	var isExcited: Bool {
		get {
			return false
		}
	}

	var isReadyToParty: Bool {
		return isExcited
	}
}

struct Eeyore: Excitable {
	func becomeExcited() {
		// Not possible
	}
}

let instance = Eeyore()
instance.isExcited

//: [Next](@next)
