//
//  main.swift
//  Assignment1
//
//  Dylan Secreast
//  CIS 399 - 1/18/17
//

var triathlonSimulation = TriathlonEvent(triathlon: Triathlon.ironman)

triathlonSimulation.register(Swimmer(name: "Cassi"))
triathlonSimulation.register(Swimmer(name: "Jason"))
triathlonSimulation.register(Swimmer(name: "Kathy"))
triathlonSimulation.register(Cyclist(name: "Asia"))
triathlonSimulation.register(Cyclist(name: "David"))
triathlonSimulation.register(Runner(name: "Sigh"))
triathlonSimulation.register(Runner(name: "Becky"))
triathlonSimulation.register(Athlete(name: "Charles"))
triathlonSimulation.register(Athlete(name: "Chuck"))

triathlonSimulation.simulate()

print("Winner!:", triathlonSimulation.getWinner()!)


//Once the event has been performed, if there is a winner print the text "<winner name> wins first place with a total time of <total time> minutes!".  If there is no winner print the text "No one finished the race!".
