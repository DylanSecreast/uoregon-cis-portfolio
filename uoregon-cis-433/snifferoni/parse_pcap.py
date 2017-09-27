#!/usr/bin/env python

import dpkt
import sys

if len(sys.argv) != 2 or sys.argv[1].endswith(".pcap") == False:
    print "Usage: python parse_pcap.py PCAP_FILE.pcap"
    sys.exit()

try:
    pcap = dpkt.pcap.Reader(open(sys.argv[1], 'r'))
except Exception:
    print "Error opening", sys.argv[1], "\nDoes file exist?"
    sys.exit(1)

counter = 0
ipcounter = 0
tcpcounter = 0
udpcounter = 0

for ts, pkt in pcap:
    counter += 1
    eth = dpkt.ethernet.Ethernet(pkt)

    if eth.type != dpkt.ethernet.ETH_TYPE_IP:
       continue

    ip = eth.data
    ipcounter += 1

    if ip.p == dpkt.ip.IP_PROTO_TCP:
       tcpcounter += 1

    if ip.p == dpkt.ip.IP_PROTO_UDP:
       udpcounter += 1

print "Total packets in .pcap file: ", counter
print "Total IP packets: ", ipcounter
print "Total TCP packets: ", tcpcounter
print "Total UDP packets: ", udpcounter
