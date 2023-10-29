/* TCP server
   ----------
   1. Declare a variable for the socket.
   2. specify the family, protocol, IP addr and the port number.
   3. create a socket using socket()
   4. Bind IP addr and port num.
   5. Listen and accept client's request for connection.
   6. Read and display the client's message.
   (7. Send a response back to the client - for 2way)
   7. continue the chat.
   8. Terminate and close the chat.
   
   TCP client
   ----------
   1. Declare a variable for the socket.
   2. specify the family, protocol, IP addr and the port number.
   3. create a socket using socket()
   4. connect using connect() and connect with the server.
   5. Send message to server.
   (6. Receive response from server and process the message - for 2way)
   6. continue the chat.
   7. Terminate and close the chat.
   
   
   sliding window: Go back
   -----------------------
   SWS - sliding window size = MAX_SEQ_NO-1
   LFS - lasf frame size
   LAF - last acknowledged frame
   MAX_SEQ_NO - maximum sequence
   
   Sender:
   Repeat the following until message is 'end':
    * if SWS>=(LFS-LAR)
		1. transmit the nxt frame.
		2. increment LFS
		3. listen for ack 
		4. if ack is required, set LAR to the received value.
	* else, transmit frames from LAR until an ack is received.
	
   Receiver:
   N - next frame to be received 
   Repeat the following until message is 'end':
	* if SEQ_NO of the packet received = N
		1. accept the packet and store it.
		2. increment N.
	* else, discard the packet.
   
   
   Selective repeat
   ----------------
   SWS - sliding window size = (MAX_SEQ_NO+1)/2
   LFS - lasf frame size
   LAF - last acknowledged frame
   MAX_SEQ_NO - maximum sequence
   
   Sender:
   Repeat the following until message is 'end':
   * if SWS>=(LFS-LAR)
		1. transmit the nxt frame.
		2. increment LFS
		3. listen for ack 
		4. if ack is required, set LAR to the received value.
   * else, transmit frames from LAR until an ack is received.
   
   Receiver:
   N - next frame to be received 
   RWS - Receiver window size 
   LFR - last frame received
   LAF - Last Acknowledged frame 
   Repeat until message is "end" :
    * if RWS>=(LAF - LFR)
	    1. receive the next frame 
		2. if no error, store it. Otherwise discard it
		3. if inorder frame send ack, otherwise send a negative ack for the desired frame.
	    4. calculate LFR 
	*else, discard frames received and send request for correct frame.



   Stop and wait
   -------------
   
   Server:
   1. create a socket using socket()
   2. Bind the IP address and port number 
   3. Listen for frames 
   4. After receiving frame send ack 
   5. Repeat 3 and 4 until message "end" is received.
   6. close the socket.
   
   Client:
   1. create a socket using socket()
   2. connect to server using connect().
   3. Listen for frames.
   4. After receiving frames, send ack 
   5. Repeat 3 and 4 until message "end" 
   6. Close the socket.


*/
   