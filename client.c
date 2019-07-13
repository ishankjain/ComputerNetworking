#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <netdb.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <unistd.h>

#include <errno.h>

 

int main(int argc, char const *argv[])

{

        char sendMessage[512],receiveMessage[512];

        int sock, result; 

        struct hostent *host;

        struct sockaddr_in serverAdd; 

        host = gethostbyname(argv[1]);     

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)

        {

            perror("Socket creation failed");

			exit(1);

        }

        serverAdd.sin_family = AF_INET;    

        serverAdd.sin_port = htons(5000);  

        serverAdd.sin_addr = *((struct in_addr *)host->h_addr);

        bzero(&(serverAdd.sin_zero),8);

        if (connect(sock, (struct sockaddr *)&serverAdd, sizeof(struct sockaddr)) == -1)

        {

            perror("Connection failed");

            exit(1);

        }
        FILE *fp = fopen("prova.jpg", "rb");
        int b;
        while( (b = fread(sendbuffer, 1, sizeof(sendbuffer), fp))>0 ){
        	send(sfd, sendbuffer, b, 0);
    	}
    	fclose(fp);

        while(1)

        {

                        printf("\n2017UCU1546_ftp-client > ");

                        fgets(sendMessage,512,stdin);

                        send(sock,sendMessage,strlen(sendMessage), 0);

                        // result = recv(sock,receiveMessage,1024,0);

                        // receiveMessage[result] = '\0';

                        // printf("\nRecieved Message: %s " , receiveMessage);


        }  

        return 0;

}

