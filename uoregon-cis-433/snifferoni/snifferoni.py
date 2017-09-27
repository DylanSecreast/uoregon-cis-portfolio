#!/usr/bin/python
import socket
from struct import *
import datetime
import pcapy
import sys
import time
import DDoSDetection as ddos
import cPickle as pickle
import sys


def main(argv):
    #List all devices
    devices = pcapy.findalldevs()
    print devices

    #Prompt user the device they would like to sniff
    print "Available devices are :"
    for d in devices :
        print d

    dev = raw_input("Enter device name to sniff : ")
    minutes = input("Enter minutes to scan : ")
    print "Sniffing device " + dev

    # open device
    # Arguments:
    #   device
    #   snaplen (maximum number of bytes to capture _per_packet_)
    #   promiscious mode (1 for true)
    #   timeout (in milliseconds)

    cap = pcapy.open_live(dev , 65536 , 1 , 0)
    packetSample = ddos.PacketSample()
    #Sniffing loop


    t_end = time.time() + 60 * minutes
    while time.time() < t_end:
        (header, packet) = cap.next()
        i = int(time.time()%4)
        print ('%s: captured %d bytes, truncated to %d bytes' %(datetime.datetime.now(), header.getlen(), header.getcaplen()))
        packetSample = parse_packet(packet, packetSample)


    #Get packet samples from database
    #If no file, skip to create file
    packetPopulation = ddos.PacketPopulation()
    try:
        with open("packetPopData.p", "rb") as x:
            packetPopulation = pickle.load(x)
            #Analyze data
    except: pass

    print "PACKET CAPTURE COMPLETE :  \n"
    print "\nPackets captured : "
    print "\tTotal Packets Captured : " + str(packetSample.numPackets['Any'])
    print "\tUDP Packets Captured : " + str(packetSample.numPackets['UDP'])
    print "\tTCP Packets Captured : " + str(packetSample.numPackets['TCP'])
    print "\tICMP Packets Captured : " + str(packetSample.numPackets['ICMP'])
    print "\tSYN Packets Captured : " + str(packetSample.numPackets['SYN'])
    packetPopulation = ddos.analyze(packetPopulation, packetSample)
    packetSample = packetPopulation.packetSamples[-1]
    ddos.determineAttack(packetSample)
    with open("packetPopData.p", "wb") as x:
        pickle.dump(packetPopulation, x)



#Convert a string of 6 characters of ethernet address into a dash separated hex string
def eth_addr (a) :
    b = "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x" % (ord(a[0]) , ord(a[1]) , ord(a[2]), ord(a[3]), ord(a[4]) , ord(a[5]))
    return b

#Parse packets
def parse_packet(packet, packetSample) :

    #Parse ethernet header
    eth_length = 14

    eth_header = packet[:eth_length]
    eth = unpack('!6s6sH' , eth_header)
    eth_protocol = socket.ntohs(eth[2])
    packetSample.numPackets['Any'] += 1
    #Parse IP packets, IP Protocol number = 8
    if eth_protocol == 8 :
        #Parse IP header
        #Take first 20 characters for the IP header
        ip_header = packet[eth_length:20+eth_length]

        #Unpack
        iph = unpack('!BBHHHBBH4s4s' , ip_header)

        version_ihl = iph[0]
        version = version_ihl >> 4
        ihl = version_ihl & 0xF

        iph_length = ihl * 4

        ttl = iph[5]
        protocol = iph[6]
        s_addr = socket.inet_ntoa(iph[8]);
        d_addr = socket.inet_ntoa(iph[9]);

        #TCP protocol
        if protocol == 6 :
            t = iph_length + eth_length
            tcp_header = packet[t:t+20]

            #Unpack
            tcph = unpack('!HHLLBBHHH' , tcp_header)

            source_port = tcph[0]
            dest_port = tcph[1]
            sequence = tcph[2]
            acknowledgement = tcph[3]
            doff_reserved = tcph[4]
            tcph_length = doff_reserved >> 4
            packetSample.numPackets['TCP'] += 1
            #Convert flag segment to binary
	    flags = str(format(tcph[5],'010b'))
            #Parse and add to array
            flag_array = []
	    for flag in flags:
	    	flag_array.append(flag)
	    h_size = eth_length + iph_length + tcph_length * 4
            data_size = len(packet) - h_size
            #Filters for only incoming SYNs, not ACKs
            if (flag_array[8] == '1'):
                packetSample.numPackets['SYN'] += 1
            #Grab remaining packet as data
            data = packet[h_size:]


        #ICMP Packets
        elif protocol == 1 :
            u = iph_length + eth_length
            icmph_length = 4
            icmp_header = packet[u:u+4]

            #Unpack
            icmph = unpack('!BBH' , icmp_header)
            icmp_type = icmph[0]
            code = icmph[1]
            checksum = icmph[2]
            h_size = eth_length + iph_length + icmph_length
            data_size = len(packet) - h_size
            packetSample.numPackets['ICMP'] += 1
            #Grab data
            data = packet[h_size:]


        #UDP packets
        elif protocol == 17 :
            u = iph_length + eth_length
            udph_length = 8
            udp_header = packet[u:u+8]

            #Unpack
            udph = unpack('!HHHH' , udp_header)

            source_port = udph[0]
            dest_port = udph[1]
            length = udph[2]
            checksum = udph[3]
            h_size = eth_length + iph_length + udph_length
            data_size = len(packet) - h_size
            packetSample.numPackets['UDP'] += 1
            #Grab data
            data = packet[h_size:]

    return packetSample

if __name__ == "__main__":
  main(sys.argv)
