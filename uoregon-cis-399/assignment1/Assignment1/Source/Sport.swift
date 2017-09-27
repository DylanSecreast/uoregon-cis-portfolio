//
//  Sport.swift
//  Assignment1
//
//  Dylan Secreast
//  CIS 399 - 1/18/17
//

enum Sport: CustomStringConvertible {
    case swimming, cycling, running
    
    public var description : String {
        switch self {
        case .swimming: return "swimming"
        case .cycling: return "cycling"
        case .running: return "running"
        }
    }
    
}
