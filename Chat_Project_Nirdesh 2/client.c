/* Internet domain TCP client. 
   Usage: ./client <hostname> <port> 
   Really only useful with server
   Original code from Linux HowTos.
*/ 


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 


void* user_send(void* newsockfd);

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;
    int loop = 1;

    char buffer[256];
    

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        puts("ERROR opening socket");


    server = gethostbyname(argv[1]);


    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }


    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        puts("ERROR connecting");


   printf("[CLIENT]::CONNECTED TO SERVER. Please type request. \n");
   pthread_t thread_x; 
   pthread_create(&thread_x, NULL, user_send, &sockfd);

    while (loop == 1) {

        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if (n < 0)
            puts("ERROR reading from socket");

        if (strcmp(buffer, "[SERVER]/QUIT") == 0) {
            loop = 2;
        }

        else {
            printf("%s\n", buffer);
        }
    }
    puts("Exit request from server processed. Client Disconnected.");
    close(sockfd);
    return (0);
}


void*  user_send(void* newsockfd){
    
    char buffer[256], buffer_send[256];
    int error_check;
    int sockfd = *(int*)newsockfd;
    int loop = 1;

    while (loop = 1) {
        bzero(buffer, 256);
        fgets(buffer_send, 255, stdin);
        strncpy(buffer, buffer_send, strlen(buffer_send) - 1);  // 

        error_check = write(sockfd, buffer, strlen(buffer));
        
        if (error_check < 0)
            puts("Write error.");
    }
  }