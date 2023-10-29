#include &lt;arpa/inet.h&gt;
#include &lt;fcntl.h&gt;
#include &lt;netdb.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/socket.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;unistd.h&gt;

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define MESSAGE_LIMIT 10

int main() {
int server_socket, client_socket;
struct sockaddr_in server_address, client_address;
// char buffer[MAX_BUFFER_SIZE];
int buffer;
int current_sequence = 0;

// Create server socket
server_socket = socket(AF_INET, SOCK_STREAM, 0);

if (server_socket == -1) {
perror(&quot;Socket creation failed&quot;);
exit(EXIT_FAILURE);
}

// Prepare server address structure
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = INADDR_ANY;
server_address.sin_port = htons(SERVER_PORT);

// Bind the socket to the specified IP and port
if (bind(server_socket, (struct sockaddr *)&amp;server_address,
sizeof(server_address)) &lt; 0) {
perror(&quot;Binding failed&quot;);
exit(EXIT_FAILURE);
}

// Start listening for incoming connections
if (listen(server_socket, 5) &lt; 0) {
perror(&quot;Listening failed&quot;);
exit(EXIT_FAILURE);
}

printf(&quot;Server listening on port %d...\n&quot;, SERVER_PORT);

// Accept the first client
socklen_t client_address_size = sizeof(client_address);
client_socket = accept(server_socket, (struct sockaddr *)&amp;client_address,
&amp;client_address_size);

if (client_socket &lt; 0) {
perror(&quot;Accept failed&quot;);
exit(EXIT_FAILURE);
}

printf(&quot;New client connected: %s\n&quot;, inet_ntoa(client_address.sin_addr));

// Enter a loop for two-way communication
while (1) {
// Receive message from the client
// memset(buffer, 0, sizeof(buffer));
int bytes_received = recv(client_socket, &amp;buffer, sizeof(buffer), 0);
if (bytes_received &lt; 0) {
perror(&quot;Receiving failed&quot;);
exit(EXIT_FAILURE);
}

if (bytes_received == 0) {
printf(&quot;Client disconnected\n&quot;);
break;
}

printf(&quot;Received message from client: %d\n&quot;, buffer);

// Process data or perform operations here

// Send a reply to the client
printf(&quot;Enter a reply to send (or &#39;exit&#39; to quit): &quot;);
// fgets(buffer, sizeof(buffer), stdin);

// Remove newline character from the input
// buffer[strcspn(buffer, &quot;\n&quot;)] = 0;

// Check if the server wants to exit
// if (strcmp(buffer, &quot;exit&quot;) == 0)
// break;

// Send the reply to the client
if (send(client_socket, &amp;buffer, sizeof(int), 0) &lt; 0) {
perror(&quot;Sending failed&quot;);
exit(EXIT_FAILURE);
}
}

// Close the client socket
close(client_socket);

// Close the server socket
close(server_socket);

return 0;
}