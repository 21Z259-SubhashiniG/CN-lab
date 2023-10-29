#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/socket.h&gt;
#include &lt;arpa/inet.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;netdb.h&gt;
#include &lt;fcntl.h&gt;
#include &lt;unistd.h&gt;
#include &lt;time.h&gt;

#define MAX_BUFFER_SIZE 1024
#define SERVER_IP &quot;10.1.22.246&quot;
#define SERVER_PORT 8080
#define MESSAGE_LIMIT 10

int main() {
int client_socket;
struct sockaddr_in server_address;
char message[MAX_BUFFER_SIZE];
// char buffer[MAX_BUFFER_SIZE];
int buffer;
int sequence_number = 0;

// Create client socket
client_socket = socket(AF_INET, SOCK_STREAM, 0);

if (client_socket == -1) {
perror(&quot;Socket creation failed&quot;);
exit(EXIT_FAILURE);
}

// Prepare server address structure
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
server_address.sin_port = htons(SERVER_PORT);

// Connect to the server
if (connect(client_socket, (struct sockaddr *)&amp;server_address, sizeof(server_address)) &lt; 0) {
perror(&quot;Connection failed&quot;);
exit(EXIT_FAILURE);
}

printf(&quot;Connected to server\n&quot;);

// Enter a loop for two-way communication
while (1 &amp;&amp; sequence_number&lt;MESSAGE_LIMIT) {
// printf(&quot;Enter a message to send (or &#39;exit&#39; to quit): &quot;);
// fgets(message, sizeof(message), stdin);

// Remove newline character from the input
// message[strcspn(message, &quot;\n&quot;)] = 0;

// Send the message to the server
if (send(client_socket, &amp;sequence_number, sizeof(int), 0) &lt; 0) {
perror(&quot;Sending failed&quot;);

exit(EXIT_FAILURE);
}

// Check if the client wants to exit
if (strcmp(message, &quot;exit&quot;) == 0)
break;

// Receive the server&#39;s reply
// memset(buffer, 0, sizeof(buffer));
int bytes_received = recv(client_socket, &amp;buffer, sizeof(int), 0);
if (bytes_received &lt; 0) {
perror(&quot;Receiving failed&quot;);
exit(EXIT_FAILURE);
}
if (buffer==sequence_number){
sequence_number+=1;
}
else{
continue;
}
sleep(1);

// printf(&quot;Server reply: %s\n&quot;, buffer);
}

// Close the client socket
close(client_socket);

return 0;

}