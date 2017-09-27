import socket
import threading

bind_ip = "192.168.1.4"
bind_port = 1420

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((bind_ip,bind_port))

server.listen(5)

print "[*] Listening on %s:%d" % (bind_ip,bind_port)

#client handling thread
def handle_client(client_socket):

	#print client payload
	request = client_socket.recv(1024)

	print "[*] Received: %s" % request

	#send response
	client_socket.send("ACK!")
	client_socket.close
while True:

	client,addr = server.accept()

	print "[*] Accepted Connection from: %s:%d" % (addr[0],addr[1])

	#handling incoming data
	client_handler = threading.Thread(target=handle_client,args=(client,))
	client_handler.start()
