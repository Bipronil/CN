#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8080
void main()
{
        char message[1024];
	int clnsock_fd;
	struct sockaddr_in svraddr,clnaddr;
	socklen_t svraddrlen=sizeof(struct sockaddr_in);
	socklen_t clnaddrlen=sizeof(struct sockaddr_in);
	clnsock_fd=socket(AF_INET,SOCK_DGRAM,0);
	svraddr.sin_family=AF_INET;
	svraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	svraddr.sin_port=htons(PORT);
	while(1)
	{
		memset(message,0,sizeof(message));
		
		printf("\nEnter data for UDP/IP Server:");
		gets(message);
		sendto(clnsock_fd,message,sizeof(message),0,&svraddr,svraddrlen);
		if(strcmp(message,"exit")==0)break;
		
		
	}
}
