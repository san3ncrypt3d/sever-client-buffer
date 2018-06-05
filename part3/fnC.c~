#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int socketD;
     int n;
    char req[5];
    char res[5];
    struct sockaddr_in serveradd;
 
    socketD=socket(AF_INET,SOCK_STREAM,0);
    bzero(&serveradd,sizeof serveradd);
 
    serveradd.sin_family=AF_INET;
    serveradd.sin_port=htons(22000);
 
    inet_pton(AF_INET,"127.0.0.1",&(serveradd.sin_addr));
 
    connect(socketD,(struct sockaddr *)&serveradd,sizeof(serveradd));

 
    while(1)
    {
        bzero( req, 5);
        bzero( res, 5);
        fgets(req,5,stdin); 
 
        write(socketD,req,strlen(req)+1);
        read(socketD,res,5);
        printf("%s",res);
    }
 
}
