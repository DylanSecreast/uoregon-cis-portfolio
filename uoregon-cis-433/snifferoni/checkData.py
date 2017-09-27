#!/usr/bin/python
import socket
from struct import *
import datetime
import sys
import time
import DDoSDetection as ddos
import cPickle as pickle
import sys


packetPopulation = ddos.PacketPopulation()
try:
    with open(sys.argv[1], "rb") as x:
        packetPopulation = pickle.load(x)
        #Analyze data
except: pass
packetSample = packetPopulation.packetSamples[-1]
i = 0
for packet in packetPopulation.packetSamples:

	print packet.numPackets[sys.argv[2]]

print "\nPercentages : "
print "\tPercent UDP : " + str(packetSample.percentages['UDP'])+'%'
print "\tPercent TCP : " + str(packetSample.percentages['TCP'])+'%'
print "\tPercent ICMP : " + str(packetSample.percentages['ICMP'])+'%'
print "\tPercent SYN : " + str(packetSample.percentages['SYN'])+'%'
print "\nAverages : "
print "\tAverage UDP : " + str(round(packetSample.averagePackets['UDP'],2))
print "\tAverage TCP : " + str(round(packetSample.averagePackets['TCP'],2))
print "\tAverage ICMP : " + str(round(packetSample.averagePackets['ICMP'],2))
print "\tAverage SYN : " + str(round(packetSample.averagePackets['SYN'],2))
print "\tAverage Total : " + str(round(packetSample.averagePackets['Any'],2))
print "\nPackets captured : "
print "\tTotal Packets Captured : " + str(packetSample.numPackets['Any'])
print "\tUDP Packets Captured : " + str(packetSample.numPackets['UDP'])
print "\tTCP Packets Captured : " + str(packetSample.numPackets['TCP'])
print "\tICMP Packets Captured : " + str(packetSample.numPackets['ICMP'])
print "\tSYN Packets Captured : " + str(packetSample.numPackets['SYN'])
print "\nUpperBound Outer captured : "
print "\tTotal Packets Captured : " + str(packetSample.upperboundOuter['Any'])
print "\tUDP Packets Captured : " + str(packetSample.upperboundOuter['UDP'])
print "\tTCP Packets Captured : " + str(packetSample.upperboundOuter['TCP'])
print "\tICMP Packets Captured : " + str(packetSample.upperboundOuter['ICMP'])
print "\tSYN Packets Captured : " + str(packetSample.upperboundOuter['SYN'])
print "\nUpperBound Inner captured : "
print "\tTotal Packets Captured : " + str(packetSample.upperboundInner['Any'])
print "\tUDP Packets Captured : " + str(packetSample.upperboundInner['UDP'])
print "\tTCP Packets Captured : " + str(packetSample.upperboundInner['TCP'])
print "\tICMP Packets Captured : " + str(packetSample.upperboundInner['ICMP'])
print "\tSYN Packets Captured : " + str(packetSample.upperboundInner['SYN'])
