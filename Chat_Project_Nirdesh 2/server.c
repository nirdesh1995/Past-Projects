/* Internet domain TCP server. 
   Usage: ./server <port> 
   Really only useful with client 
   Original code from Linux HowTos.

*/ 



#include <stdio.h>   // Declarations for input and output
#include <sys/types.h>      // data types used in system calls
#include <sys/socket.h>    // definitions of structures for sockets
#include <netinet/in.h>     // structures for internet domain addresses
#include <netdb.h>         // for standard library
#include <string.h>
#include <stdlib.h>
#include <unistd.h>    // for fork() ,initial idea
#include <pthread.h>    //multi-thread library 


void* multi_threading(void* sockedfd);     // for multiple threads
                           

int client_number[10];
char user_names[10][256];                    // store usernames to write on buffer for /POST messages

int main(int argc, char* argv[]){
    int i;
  
    int sockfd, newsockfd, portno;     // sockfd and newsockfd store the value by socket accept system call
    socklen_t clilen;
    char buffer[256];                    // standard buffer
    
    struct sockaddr_in serv_addr, cli_addr; //standard structure containing an internet address, defined in <netinet/inh>

    if (argc < 2) {
        fprintf(stderr, "usage %s port\n", argv[0]);    //error if server port not passed as argumenr
        exit(1);
    }



/*  --------------------------------------CREATE SOCKET --------------------------------*/



    sockfd = socket(AF_INET, SOCK_STREAM, 0);    //   AF_INET = domain of socket(internet)


   if (sockfd < 0) {                                // SOCK_STREAM = type of socket (Continuous stream best for TCP )
        puts("ERROR opening socket");
            }

    printf("=> Socket server has been created...\n");


  /* ---- Clearing buffer to start fresh to being receiving and sending  ------------------------- */ 




    bzero((char*)&serv_addr, sizeof(serv_addr));    // bzero sets all values in a buffer to zero
    portno = atoi(argv[1]);




/*  --------------------------------------SOCKET TYPE  --------------------------------*/ 



    serv_addr.sin_family = AF_INET;                    // sin_family, contains a code for the address family, set to constat AF_INEt
    serv_addr.sin_addr.s_addr = INADDR_ANY;             //contains the IP address of the host, for server this is Ip address of hopper
    serv_addr.sin_port = htons(portno);                 //htons()  converts a port number in host byte to a port number in network byte




/*  -------------------------------------- BINDING the socket  --------------------------------*/ 


    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){    
            puts("ERROR on binding");
    }       

        printf("=> Waiting for client connections..\n");



 /*  --------------------------------------Listen for client connection requests --------------------------------*/ 




    listen(sockfd, 5);      //second argument = no of waiting connections

    
    clilen = sizeof(cli_addr);            


/* -------------------------------------Create threads for each new client ---------*/ 


    while (newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen)) {
        
        pthread_t thread_x;
            pthread_create(&thread_x, NULL, multi_threading, &newsockfd);
    }

    close(newsockfd);
    close(sockfd);

    return (0);
}

/* -------------------------------------Structure for new threads-----------------------*/



void* multi_threading(void* newsocketfd)
{

    int loop = 1;
    char buffer[256],client_request[10], send_msg[256];
    int i, msg_len;
    int sockfd = *(int*)newsocketfd;



/*-----------------------------------INITIALIZE ----------------------------------------------*/

    client_number[sockfd] = 1;
   for (i = 0; i < 10; i++) {
        if (client_number[i] == 1) {
            strcpy(send_msg, "New client accepted and added.");
                msg_len = write(i, send_msg, strlen(send_msg));
                    strcpy(send_msg, "");
        }
    }



    while (loop == 1) 
    {

        bzero(buffer, 256);


        msg_len = read(sockfd, buffer, 255);

        if (msg_len < 0){
            puts("ERROR reading from socket");
        }

              printf("Msg received from %s \n", user_names[sockfd]);   // For server logs



        sscanf(buffer, "%s", client_request);                 // scan received buffer and store as client request

        if (strcmp(client_request, "/USER") == 0) 
         {

            memset(user_names[sockfd], 0, strlen(user_names[sockfd]));
            
                strncpy(user_names[sockfd], buffer + 6, strlen(buffer) - 6);  // 6 = length of name after "/USER sp"
        }


        else if (strcmp(client_request, "/POST") == 0) {
            for (i = 0; i < 10; i++) {
                if (client_number[i] == 1) {
                    strcpy(send_msg, "");
                          strcat(send_msg, user_names[sockfd]);
                              strcat(send_msg, "==> ");
                                    strcat(send_msg, buffer + 6);
                                     write(i, send_msg, strlen(send_msg));
                }
            }
        }



        else if (strcmp(client_request, "/WHO") == 0)
         {
            strcpy(send_msg, "");
                strcat(send_msg, "list of clients ::\n");
            for (i = 0; i < 10; i++)
             {
                if (client_number[i] == 1) 
                {
                    strcat(send_msg, user_names[i]);
                    strcat(send_msg, "\n");
                }
            }
            write(sockfd, send_msg, strlen(send_msg));
        }

                 else if (strcmp(client_request, "/HELP") == 0)
                        {

            strcpy(send_msg, "");
               strcat(send_msg, "Executable requests:\n");
                    strcat(send_msg, "'/USER - Login with the given name\n");
                       strcat(send_msg, "'/POST -  Post message to all users\n");
                           strcat(send_msg, "'/WHO - Get list of logged in users\n");
                                 strcat(send_msg, "'/HELP - Show list of protocol operations\n");
                                      strcat(send_msg, "'/QUIT - Disconnect from the server\n");
            write(sockfd, send_msg, strlen(send_msg));
                           
                            }

                           else if (strcmp(client_request, "/QUIT") == 0)

                            {
     
                             printf("The following user has disconnected : %s \n", user_names[sockfd]);
                                client_number[sockfd] = 0;
                                   loop = 2;
                                     strcpy(send_msg, "[SERVER]/QUIT");
                                        write(sockfd, send_msg, strlen(send_msg));
                                  } 
    }
    close(sockfd);
}