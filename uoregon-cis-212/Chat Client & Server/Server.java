package com.dylansecreast.core;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {
	private static final int PORT = 12345;
	private ConcurrentLinkedQueue<ObjectSocket> _queue;
	private String lastMessage = "you're the first to connect!";

	//// CONSTRUCTOR ////
	public Server() {
		_queue = new ConcurrentLinkedQueue<ObjectSocket>();

		ExecutorService executorService = Executors.newCachedThreadPool();
		executorService.execute(new AcceptRunnable());
		executorService.execute(new IORunnable());
		executorService.shutdown();
	}	// end Server() constructor

	private class ObjectSocket {
		private Socket _socket;
		private ObjectInputStream _inputStream;
		private ObjectOutputStream _outputStream;

		public ObjectSocket(Socket socket) {
			_socket = socket;
			try {
				_outputStream = new ObjectOutputStream(_socket.getOutputStream());
				_outputStream.flush();
				_inputStream = new ObjectInputStream(_socket.getInputStream());
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}	// end ObjectSocket() constructor

		public ObjectInputStream getInputStream() {
			return _inputStream;
		}	// end getInputStream()

		public ObjectOutputStream getOutputStream() {
			return _outputStream;
		}	// end getOutputStream()

	}	// end class ObjectSocket

	private class AcceptRunnable implements Runnable {
		private int clientNumber = 0;

		@Override
		public void run() {
			try {
				System.out.println("Creating new server socket.");
				@SuppressWarnings("resource")
				ServerSocket serverSocket = new ServerSocket(PORT);
				boolean running = true;
				while (running) {
					if (clientNumber < 1) {
						System.out.println("Waiting for first client connection...");
					}
					else {
						System.out.println("Waiting for next client connection...");
					}
					Socket socket = serverSocket.accept();
					_queue.offer(new ObjectSocket(socket));
					clientNumber++;					// if new client successfully connects, increment clientNumber counter
					if (clientNumber == 1) {		// if first client to connect:
						broadcastMessage("[[ Client #" + clientNumber + " has connected, " + lastMessage + " ]]");		// broadcast to clients
						System.out.println("Client #" + clientNumber + " has successfully connected to " + socket.getLocalSocketAddress());		// log in console
					}
					else if (clientNumber > 1) {	// for every next client to connect:
						broadcastMessage("[[ Client #" + clientNumber + " has connected. ]]");
						broadcastMessage("[[ Last message: " + lastMessage + " ]]");		// broadcast to clients
						System.out.println("Client #" + clientNumber + " has successfully connected to " + socket.getLocalSocketAddress());		// log in console
					}
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}	// end run()
	}	// end class AcceptRunnable

	private class IORunnable implements Runnable {
		@Override
		public void run() {
			boolean running = true;
			while (running) {
				for (ObjectSocket objectSocket : _queue) {
					// Try/catch inside loop so if a read fails,
					// it will continue to read the rest of the clients
					ObjectInputStream inputStream = objectSocket.getInputStream();
					try {
						// Check for available bytes to prevent block on readUTF() call
						if (inputStream.available() > 0) {
							String message = inputStream.readUTF();
							broadcastMessage(message);
							lastMessage = message;
						}
					} catch (IOException ex) {
						System.out.println("Server Warning: Unable to read from " + objectSocket);
					}
				}
			}
		}	// end run()
	}	// end class IORunnable


	private void broadcastMessage(String message) {
		for (ObjectSocket objectSocket : _queue) {
			// Try/catch inside loop so that one failed
			// write does not prevent remaining writes
			ObjectOutputStream outputStream = objectSocket.getOutputStream();
			try {
				outputStream.writeUTF(message);
				outputStream.flush();
			} catch (IOException ex) {
				System.out.println("Server Warning: Unable to send message to " + objectSocket);
			}
		}
	}	// end broadcastMessage()


	public static void main(String[] args) {
		new Server();
	}	// end main()

}	// end class Server
