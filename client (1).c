#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<strings.h>

int main(int argc, char *argv[]){
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_adder;
    int n;
if(argc<3)
{
fprintf(stderr,"user %s hostname port\n",argv[0]);
exit(1);
}

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
    error("error opening socket");
    exit(1):
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_addr.sin_port=htons(atoi(arg[2]));
    
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))<0){
    error("error in connecting");
    exit(1);
    }
    
    printf("please enter the mess");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    
    n=write(sockfd,buffer, strlen(buffer));
    if(n<0){
    error("error writing from socket");
    exit(1);
    }
    
    bzero(buffer,256);
    n=read(newsockfd,buffer,255);
    
    if(n<0){
    error("error writing to socket");
    exit(1);
    }
    printf("%s\n",buffer);
    return 0;
    }
