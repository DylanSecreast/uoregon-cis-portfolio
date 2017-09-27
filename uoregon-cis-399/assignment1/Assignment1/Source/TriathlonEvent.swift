//
//  TriathlonEvent.swift
//  Assignment1
//
//  Dylan Secreast
//  CIS 399 - 1/18/17
//

class TriathlonEvent {
    var triathlon: Triathlon                                // #1
    private(set) var eventPerformed: Bool = false           // #3
    var participantDict = [String:Int]()                    // #4.1
    var currentlyRegistered: [Participant] = []             // #5.1
    var randomValue: Double                                 // #7.1
    
    func register(_ participant: Participant) -> () {   // #4
        guard !eventPerformed else {
            fatalError()
        }
        participantDict[participant.name] = 0
        currentlyRegistered.append(participant) // #5.2
    }
    
    var registeredParticipants: [Participant] { // #5
        get {
            return currentlyRegistered
        }
    }

    func raceTime(for participant: Participant) -> Int? { // #6
        guard let time = participantDict[participant.name] else {
            return nil
        }
        return time
    }
    
    func simulate(_ sport: Sport, for participant: Participant, randomValue: Double) -> () {  // #7
        guard let time = participantDict[participant.name] else {
            return
        }
        print(participant.name + " is about to begin " + sport.description)
        if sport == participant.favoriteSport || randomValue >= 0.05 {
            let simTime = participant.completionTime(for: sport, in: triathlon)
            participantDict[participant.name] = time + simTime
            print(participant.name, "finished the", sport.description, "event in", simTime, "minutes; their total race time is now", participantDict[participant.name]!)
        }
        if sport != participant.favoriteSport && randomValue < 0.05 {
            participantDict[participant.name] = nil
            print(participant.name, "could not finish the", sport.description, "event and will not finish the race")
        }
    }
    
    func simulate() -> () { // #8
        guard !eventPerformed else {
            fatalError()
        }
        for sport in Triathlon.Sports {
            for participant in currentlyRegistered {
                simulate(sport, for: participant, randomValue: randomValue)
            }
            print("KEKKEKEKEKEKEK")
        }
        eventPerformed = true
    }
    
    var winner: Participant? {  // #9
        get {
            guard eventPerformed else {
                fatalError()
            }
            var currentWinner: Participant?
            var currentTime: Int = 0
            for (name, time) in participantDict {
                if time < currentTime {
                    currentTime = time
                    for participant in currentlyRegistered {
                        if participant.name == name {
                            currentWinner = participant
                        }
                    }
                }
            }
            return currentWinner
        }
    }
    
    func getWinner() -> Participant? {
        return winner
    }
    
    init(triathlon: Triathlon) {    // #2
        self.triathlon = triathlon
        randomValue = Double.random()   // #7.1
    }
  
}
