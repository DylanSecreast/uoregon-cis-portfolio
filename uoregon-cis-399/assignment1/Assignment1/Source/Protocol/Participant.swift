//
//  Participant.swift
//  Assignment1
//
//  Dylan Secreast
//  CIS 399 - 1/18/17
//

protocol Participant {
    init(name: String)
    var name: String { get }
    var favoriteSport: Sport? { get }
    func completionTime(for sport: Sport, in triathlon: Triathlon) -> Int
    func completionTime(for sport: Sport, in triathlon: Triathlon, randomValue: Double) -> Int
}

extension Participant {
    func metersPerMinute(for sport: Sport, randomValue: Double) -> Int {
        var value: Double
        switch sport {
        case .swimming:
            value = 43
        case .cycling:
            value = 500
        case .running:
            value = 157
        }
        
        var modifier = 0.85 + (randomValue * 0.3)
        if let favoriteSport = self.favoriteSport {
            if favoriteSport == sport {
                modifier += 0.05
            }
            else {
                modifier -= 0.1
            }
        }
        
        return Int(value * modifier)
    }
    
    func completionTime(for sport: Sport, in triathlon: Triathlon) -> Int {
        return completionTime(for: sport, in: triathlon, randomValue: Double.random())
    }
    
    func completionTime(for sport: Sport, in triathlon: Triathlon, randomValue: Double) -> Int {
        let distance = triathlon.distance(for: sport)
        let mpm = metersPerMinute(for: sport, randomValue: randomValue)
        return distance / mpm
    }
    
}




