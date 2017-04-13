

#ifndef __L_MULTICAST_H__
#define __L_MULTICAST_H__

#include "l_message.h"
#include "l_thread.h"
#include "l_m_queue.h"
#include "l_multicast_util.h"

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



#define BUFFERSIZE 256

class L_Multicast:public L_Thread{
  protected:

    L_M_Queue<L_Message*>& m_queue;
    std::string m_name;
    char * m_group;
    int m_port;
    int m_fd; 

    struct sockaddr_in m_addr;

  public:
    
    L_Multicast(L_M_Queue<L_Message*>& queue,std::string name,char * group, int port); 
    void setupConnection(char * group, const int port);
    
    virtual int start();
    virtual void* run();
};


#endif
