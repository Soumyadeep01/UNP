//udp client driver program
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#define PORT 5000 
#define MAXLINE 1000

int main()
{
char buffer[100];
char *message="hello server";
int sockfd,n;
struct sockaddr_in servaddr;
//clear servaddr
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(PORT);
servaddr.sin_family=AF_INET;

//create datagram socket
sockfd=socket(AF_INET,SOCK_DGRAM,0);
//CONNECT TO SERVER
if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
{
printf("\n Error:connect failed \n");
exit(0);
}

//request to send datagram
//no need to specify server address in sendto
//connect stores the peers IP and port
sendto(sockfd,message,MAXLINE,0,(struct sockaddr*)NULL,sizeof(servaddr));

//waiting for response
recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)NULL,NULL);
puts(buffer);
//close the descriptor
close(sockfd);
}

