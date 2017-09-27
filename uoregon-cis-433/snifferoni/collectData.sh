#!/bin/bash

while :
do
    trap '{ echo "Canceling data collection.." ; exit 1; }' INT 
    python -c "print 'wlan0\n' + '5\n'" | ./snifferoni.py
    wait
    echo 'Iteration complete.'
    if [ $? -eq 139 ]; then
        echo "segfault"
        exit 1
    fi
done
    
