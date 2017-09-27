import sys
import socket
import threading

def server_loop(local_host, local_port, remote_host, remote_port, receive_first):

	server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	try:
			server.bind((local_host,local_port))
	except:
			print "[!!] FAILED to listen on %s:%d" % (local_host, local_port)
			print "[!!] Check for other listening sockets/Check permissions"
			sys.exit(0)

	print "[!!] Listening on %s:%d" % (local_host, local_port)

	server.listen(5)

	while True:
		client_socket, addr = server.accept()

		#Print out connection information
		print "[===>] Received connection from %s:%d" % (addr[0], addr[1])
		#Thread to talk to remote host
		proxy_thread = threading.Thread(target=proxy_handler, args=(client_socket,remote_host,remote_port,receive_first))

		proxy_thread.start()


def proxy_handler(client_socket, remote_host, remote_port, receive_first):
	#Create remote host connection
	remote_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	remote_socket.connect((remote_host,remote_port))
	#Receive data from remote if receive first = true
	if receive_first:
			remote_buffer = receive_from(remote_socket)
			#Send to buffer, modifiy to send to file
			hexdump(remote_buffer)
			#Send to response handler
			remote_buffer = response_handler(remote_buffer)

			#Send data to local client if needed
			if len(remote_buffer):
				print "[<===] Sending %d bytes to localhost" % len(remote_buffer)
				client_socket.send(remote_buffer)
	#Loop to send/receive from local/remote
	while True:
			#Read from local
			local_buffer = receive_from(client_socket)

			if len(local_buffer):
				print "[==>] Received %d bytes from localhost" % len(local_buffer)
				#Dump info
				hexdump(local_buffer)
				#Send to request handler
				local_buffer = request_handler(local_buffer)
				#Send the data to remote host
				remote_socket.send(local_buffer)
				print "[<===] Sent to Remote"

			#Get Response
			remote_buffer = receive_from(remote_socket)
			if len(remote_buffer):
				print "[===>] Received %d bytes from remote" % len(remote_buffer)
				#Dump data
				hexdump(remote_buffer)
				#Send to response handler
				remote_buffer = response_handler(remote_buffer)

				#Send to local host
				client_socket.send(remote_buffer)
				print "[<===] Sent to localhost"
			#If no more data
			if not len(remote_buffer) or not len(local_buffer):
				client_socket.close()
				remote_socket.close()
				print "***No more data, closing connections***"

				break
#hexdump, dumps data in hex
def hexdump(src, length=16):
	result = []
	digits = 4 if isinstance(src, unicode) else 2
	for i in xrange(o, len(src), length):
		s = src[i:i+length]
		hexa = b' '.join(["%0*X" % (digits, ord(x))  for x in s])
		text = b''.join([x if 0x20 <= ord(x) < 0x7F else b'.'  for x in s])
		result.append( b"%04X   %-*s   %s" % (i, length*(digits + 1), hexa, text))
		print b'\n'.join(result)


def receive_from(connection):
	buffer = ""
	#set timeout
	connection.settimeout(2)

	try:
			#Read from buffer until empty or timeout
			while True:
					data = connection.recv(4096)

					if not data:
							break
					buffer += data
	except:
			pass

	return buffer

def request_handler(buffer):
	#do shit to the packet
	return buffer
def response_handler(buffer):
	#do shit to the packet
	return buffer


def main():
		#Determine proper number of args
		if len(sys.argv[1:]) != 5:
			print "Usage: ./proxy.py [local_host] [local_port] [remote_host] [remote_port] [receive_first]"
			print "Example: ./proxy.py 127.0.0.1 9000 10.12.132.1 9000 True"
			sys.exit(0)

		#Set up listening local host params
		local_host = sys.argv[1]
		local_port = int(sys.argv[2])

		#Set up remote target params
		remote_host = sys.argv[3]
		remote_port = int(sys.argv[4])

		#Determine if our proxy will receive first before sending
		receive_first = sys.argv[5]

		#No argument results in false
		#if True in receive_first:
		if receive_first:
			receive_first = True
		else:
			receive_first = False

		#Start listening socket
		server_loop(local_host, local_port, remote_host, remote_port, receive_first)
main()