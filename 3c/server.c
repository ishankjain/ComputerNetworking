#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include <netdb.h>

int main (int argc, char *argv[]) {

	
	if (argc < 2) {
		fprintf(stderr, "please provide port\n");
		exit(1);	
	}
	int portNumber = atoi(argv[1]);

	
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		perror("error opening socket");
		exit(0);
	}

	
	struct sockaddr_in socketAddress;
	memset(&socketAddress, 0, sizeof socketAddress);
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_addr.s_addr 	= INADDR_ANY;
	socketAddress.sin_port = htons(portNumber);

	
	int bindres = bind(serverSocket, (struct sockaddr *) &socketAddress, sizeof(socketAddress));

	if (bindres == -1) {
		perror("error in binding");
		exit(0);
	}

	
	listen(serverSocket, 3);

	int newSocket;	
	struct sockaddr_in clientAddress;
	socklen_t cLength = sizeof(clientAddress);

	newSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &cLength);

	if (newSocket == -1) {
		perror("error on accept\n");
	}

	char inMessage[256], outMessage[256];

	int n1, n2;

	pid_t p = fork();

	if (p > 0) {
		while (1) {
			memset(inMessage, 0, sizeof inMessage);
			n1 = recv(newSocket, inMessage, 255,0);
			if (n1 == -1) perror("error in reading from socket");
			printf("<client> %s", inMessage);
			if (strcmp(inMessage, "STOP_COMMAND") == 0) 
                break;
		}
	}
	else {
		while (1) {
			fgets(outMessage, 255, stdin);
			n2 = send(newSocket, outMessage, strlen(outMessage),0);
			if (strcmp(outMessage, "STOP_COMMAND") == 0) 
                break;
			if (n2 == -1) perror("error in writing to socket");
		}
	}
	close(newSocket);
	close(serverSocket);
	return 0;
	
}
