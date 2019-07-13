/*
 * server.c: Server program
 *           to demonstrate interprocess commnuication
 *           with System V message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <time.h>

#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"
#define PROJECT_ID 'M'
#define QUEUE_PERMISSIONS 0660

int k=10;

void printTime()
{
    time_t s, val = 1; 
    struct tm* current_time; 
  
    // time in seconds 
    s = time(NULL); 
  
    // to get current time 
    current_time = localtime(&s); 
  
    // print time in minutes, 
    // hours and seconds 
    printf("%02d:%02d:%02d\n", 
           current_time->tm_hour, 
           current_time->tm_min, 
           current_time->tm_sec); 
  
}

struct message_text {
    int qid;
    char buf;
};

struct message {
    long message_type;
    struct message_text message_text;
};

int main (int argc, char **argv)
{
    clock_t t1=clock();
    key_t msg_queue_key;
    int qid;
    struct message message;

    if ((msg_queue_key = ftok (SERVER_KEY_PATHNAME, PROJECT_ID)) == -1) {
        perror ("ftok");
        exit (1);
    }

    if ((qid = msgget (msg_queue_key, IPC_CREAT | QUEUE_PERMISSIONS)) == -1) {
        perror ("msgget");
        exit (1);
    }

    printf ("Server: Ready\n");

    while (k--) {
        // read an incoming message
        if (msgrcv (qid, &message, sizeof (struct message_text), 0, 0) == -1) {
            perror ("msgrcv");
            exit (1);
        }
        printf ("Server: message received at:    ");
        printTime();

        // process message
        // int length = strlen (message.message_text.buf);
        // char buf [20];
        // sprintf (buf, " %d", length);
        // strcat (message.message_text.buf, buf);
        message.message_text.buf='r';
        int client_qid = message.message_text.qid;
        message.message_text.qid = qid;

        // send reply message to client
        if (msgsnd (client_qid, &message, sizeof (struct message_text), 0) == -1) {  
            perror ("msgget");
            exit (1);
        }
        printf ("acknowledgement sent at :    ");
        printTime();
    }
}