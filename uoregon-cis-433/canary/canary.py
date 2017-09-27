import os
import sys
import time


if len(sys.argv) != 2:
    print "Usage: python canary.py hostname"
    sys.exit()

count = 0
faults = 0
hostname = sys.argv[1]

while 1:
    print ">>>>>>>>>>>>>>> Canary execution time:", count * 15 , "sec"
    ping = os.system("ping -c 5 " + hostname)
    print ""

    if ping == 0:
        print hostname, "is up!"
        print "Current fault count:", faults
    else:
		faults = faults + 1
		print hostname, "is down!"
		print "FAULT! Current fault count:", faults

    if faults == 4:		# Down for a minute
        print "\nHouston we have a problem..."
        abort = os.system("sudo shutdown")
        sys.exit(0)

    print ""
    time.sleep(15)
    count = count + 1
