//
//  Athlete.swift
//  Assignment1
//
//  Dylan Secreast
//  CIS 399 - 1/18/17
//

class Athlete: Participant {
    var name: String
    var favoriteSport: Sport? {
        get {
            return nil
        }
    }
    
    required init(name: String) {
        self.name = name
    }
    
}
