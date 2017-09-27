#!/usr/bin/python
import DDoSDetection as ddos
import cPickle as pickle

try: 
    with open("OvernightBaselineScan.p", "rb") as x:
        packetPopulation = pickle.load(x)
        print "Success"
except: pass
ddosSample = ddos.PacketSample()
ddosSample.numPackets['SYN'] = 300000
ddosSample.numPackets['Any'] = 300000


packetPopulation = ddos.analyze(packetPopulation, ddosSample)
ddos.determineAttack(packetPopulation.packetSamples[-1])