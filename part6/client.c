#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
 
int main(int argc,char **argv)
{
    int socketD;
     int n;
    char req[255];
    char res[255];
    struct sockaddr_in serveradd;
 
    socketD=socket(AF_INET,SOCK_STREAM,0);
    bzero(&serveradd,sizeof serveradd);
 
    serveradd.sin_family=AF_INET;
    serveradd.sin_port=htons(22000);
 
    inet_pton(AF_INET,"127.0.0.1",&(serveradd.sin_addr));
 
    connect(socketD,(struct sockaddr *)&serveradd,sizeof(serveradd));
 
    while(1)
    {
        bzero( req, 255);
        bzero( res, 255);
        fgets(req,255,stdin); 
 
        write(socketD,req,strlen(req)+1);
        read(socketD,res,255);
        printf("%s",res);
    }
 
}
