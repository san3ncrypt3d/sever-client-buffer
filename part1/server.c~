 
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
 
int main()
{
 
    char buffer[5];
   
    int ld, cd;
 
    struct sockaddr_in serveradd;
 
    ld = socket(AF_INET, SOCK_STREAM, 0);
 
     bzero( &serveradd, sizeof(serveradd));
 
    serveradd.sin_family = AF_INET;
    serveradd.sin_addr.s_addr = htons(INADDR_ANY);
    serveradd.sin_port = htons(22000);
 
    bind(ld, (struct sockaddr *) &serveradd, sizeof(serveradd));
 
    listen(ld, 10);
 
    cd = accept(ld, (struct sockaddr*) NULL, NULL);
 
    while(1)
    {
 
       bzero( buffer, 5);
 
        read(cd,buffer,5);
        
         
        printf("buffer recieved:   %s",buffer);
 
       write(cd, buffer, strlen(buffer)+1); 
 
    }
}
