/* CRC
   ---
   Client:
   1. Create a client socket.
   2. conect to server's IP address and port number.
   3. Get the message, generator polynomial as strings. Generator polynomial is known to both client and server.
   4. Find length of generator polynomial and append L-1 0's to the message.
   5. In a loop
		* Perform binary division between message with appended 0's and generator until remainder is of length L-1.
		* The remainder is CRC. Append it to the original mesaage.
   6. Send the message with CRC to the server.
   7. Close the socket connection and end the program.
   
   Server:
   1. Create a TCP socket and bind IP address and port number.
   2. Listen for incomming connections from the client.
   3. Accept the client connection.
   4. Receive the message with CRC.
   5. Generator is already known.
   6. In a loop:
		* perform binary division between message and generator.
		* If the final remainder is 0 , then there is no error in the message.
		* Else, the message has errors.
   7. Dispaly the result.
   8. Close the socket connection and end the program.
   


   DHCP
   ----
   Server:
   1. Create a UDP socket and setup the port number.
   2. DHCP service initialization:
		* Open a file named 'IPaddress.txt' to use IP address that can be assigned to clients.
		* Initialize a loop counter 'j' to keep track of the no.of assigned IPaddresses.
   3. DHCP server loop:
		* Listen for DHCP client request
		* Use 'select()' to wait for data on the socket.
		* When the data is received proceed with DHCP message processing.
   4. DHCP discover phase: 
		* Receive DHCP discover message.
		* Generate a unique transaction ID
		* Send DHCP offer message to the client with the assigned IP address.
   5. DHCP request phase:
		* Receive a DHCP request message
		* Send DHCP ack message to the client confirming the IP address and lease time.
   6. IP address management:
		* Update the 'IPaddress.txt' file to make the assigned IPaddress as in use.
		* Maintain a counter 'j' to track the next assigned IP address.
   7. Calculate the elpsed time since the lease was assigned to moniter the lease lifetime.
   8. If all IP addresses are assigned the server exits.
   9. Close the socket.
   
   Client:
   1. Create a UDP socket and setup the port number and the service address.
   2. DHCP discover: 
		* Send the DHCP discover message.
		* Initiates the DHCP process by requesting an IP address.
   3. DHCP offer phase: 
		* Receive a DHCP offer message.
		* The server may offer an IP address to he client along with other configuration parameters
		* Print info abt hhe assigned IP address, Transaction ID and lease time.
   4. DHCP request phase:
		* Confirm the selected IP address
		* Send a DHCP request message to the server.
   5. DHCP ack phase:
		* Receive a DHCP ack message from the server.
		* The server acknowledges the IP address.
   6. Close the socket and exit.
   
   
   
   Distance Vector:
   ---------------
   
   1. Initialize the table.
   2. If path is present:
		* mark 1 or cost if given.
		* Read source and destination nodes.
   3. Else: 
		* mark infinity.
		* Read source and destination nodes.
   4. if neighbouring(source)== destination:
		* inc Hop
		* if all nodes are visited:
				- Select mim Hop from source to destination
				- Update Hop in the table.
				- Broadcast changes to all the nodes.
		* else go to step 4.
   5. else:
		* inc Hop 
		* Assign source = neighbour
		* go to step 4.
   6. End of program.


*/