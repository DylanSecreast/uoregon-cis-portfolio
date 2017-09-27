public struct Book {
	public func sequel() -> Book? { return Book(title: "The sequel to \(title)", author: author) }
	
	public init(title: String, author: String) {
		self.title = title
		self.author = author
	}

	public let title: String
	public let author: String
}