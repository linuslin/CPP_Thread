#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include<iostream>
#include<fstream>
#include<cmath>
#include "bmpheader.h"

#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37"

int main(int argc, char *argv[])
{
     struct sockaddr_in addr;
     int fd, cnt;
     struct ip_mreq mreq;
     char message[]="Hello, this is my thread";

     /* create what looks like an ordinary UDP socket */
     if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {
	  perror("socket");
	  exit(EXIT_FAILURE);
     }

     /* set up destination address */
     memset(&addr,0,sizeof(addr));
     addr.sin_family=AF_INET;
     addr.sin_addr.s_addr=inet_addr(HELLO_GROUP);
     addr.sin_port=htons(HELLO_PORT);
    

    std::ifstream is("format3.dat");
    char c;
    char buffer[256];
    int index=0;
     
     /* now just sendto() our destination! */
     while (is.get(c)) {
        if(c==27){
//            std::cout << c;
	    buffer[index++]=c;
	    while(is.get(c)){
//            std::cout << c;
		if(c==0x0a && buffer[index-1]==0x0d){
		    buffer[index]=c;
		    if (sendto(fd,buffer,28,0,(struct sockaddr *) &addr,sizeof(addr)) < 0) {
			perror("sendto");
			exit(EXIT_FAILURE);
		    }else{
			buffer[index]='\0';
			puts(buffer);
		    }
		    index=0;
		    bzero(buffer,sizeof(buffer));
		    usleep(1000000);
		    break;
		}
		buffer[index++]=c;
	    }
	}
     }
     is.close();
     return 0;
}

