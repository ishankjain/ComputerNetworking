#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "enter server address and port\n");
        exit(1);
    }
    int portNumber = atoi(argv[2]);


    int newSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (newSocket == -1) {
        perror("error opening socket");
        exit(0);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
            fprintf(stderr,"Error, no such host\n");
            exit(0);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNumber);
    bcopy((char *)server->h_addr,(char *)&serverAddress.sin_addr.s_addr,server->h_length);

    int tmp = connect(newSocket,(struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (tmp == -1) fprintf(stderr, "Unable to connect to the server\n");

    int n1, n2;
    char inMessage[256], outMessage[256];

    pid_t p = fork();

    if (p > 0) {
        while (1) {
            fgets(outMessage, 255, stdin);
            n1 = send(newSocket, outMessage, strlen(outMessage),0);
            if (strcmp(outMessage, "STOP_COMMAND") == 0) 
                break;
            if (n1 == -1) fprintf(stderr, "ERROR writing to socket");
        }
    }
    else {
        while (1) {
            memset(inMessage, 0, sizeof inMessage);
            n2 = recv(newSocket, inMessage, 255,0);
            if (n2 == -1) fprintf(stderr, "ERROR reading from socket");
            char temp[256]={"STOP"};
            if (strcmp(inMessage, temp) == 0) {
                break;
            }
            printf("[server] %s",inMessage);
            
        }
    }

    close(newSocket);
    return 0;
}
