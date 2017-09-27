import socket

target_host = "192.168.1.4"
target_port = 1420

#create socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#connect to client
client.connect((target_host,target_port))

#send data
client.send("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n")

#recieve data
response = client.recv(4096)

print response
