#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char *argv[]){
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_adder;
    int n;
if(argc<2)
{
fprintf(stderr,"error!! no port provided\n");
exit(1);
}

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
    error("error opening socket");
    exit(1):
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(atoi(arg[1]));
    
    if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))<0){
    error("error on binding");
    exit(1);
    }
    
    listen(sockfd,5);

while(1){
    clilen=sizeof(cli_addr);
    newsockfd= accept(sockfd,(struct sockaddr *)&cli_addr, &clilen);
    
    if(newsockfd<0){
    error("error on accept");
    exit(1);
    }
    printf("new client conn_ from port no %d and ip %s\n",ntohs(cli_addr.sin_port), inet_ntoa(cli_addr.sin_addr));
    
    bzero(buffer,256);
    n=read(newsockfd,buffer,256);
    
    if(n<0){
    error("error reading from socket");
    exit(1);
    }
    
    printf("here is the message:%s\n",buffer);
    n=write(newsockfd,"i got the message");
    
    if(n<0){
    error("error writing to socket");
    exit(1);
    }}
    return 0;
    }
