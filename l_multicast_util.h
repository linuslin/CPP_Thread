

#ifndef __L_MULTICAST_UTIL_H__
#define __L_MULTICAST_UTIL_H__

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class L_Multicast_Util{
  public:
    static int connect(int& fd, const char * group, const int port, struct sockaddr_in &addr,std::string & errorMsg); 
    static ssize_t receive(int & fd, unsigned char * msgbuf,const size_t size,struct sockaddr_in& addr);    
};


#endif
