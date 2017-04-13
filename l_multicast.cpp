#include "l_multicast.h"
#include "l_multicast_util.h"

#include <string>
#include <iostream>


//tmp
#include "bmpheader.h"
//

L_Multicast::L_Multicast(L_M_Queue<L_Message*>& queue,std::string name,char * group, int port):m_queue(queue),m_name(name),m_group(group),m_port(port){}


void L_Multicast::setupConnection(char * group, const int port){
    this->m_group=group;
    this->m_port=port;
}


int L_Multicast::start()
{
    std::string errorMsg; 
    int result=0;
    if((result=L_Multicast_Util::connect(this->m_fd,this->m_group,this->m_port,this->m_addr,errorMsg))<0){
        std::cout<<"setup connection failed\n";
        return -1; 
    }else{
        return this->L_Thread::start();
    }
}


void* L_Multicast::run(){
    int result;
    ssize_t nbyte;

    int size = BUFFERSIZE;
    unsigned char msgbuf[size];
    L_Message * msg; 
    while(1){ // need to add condition var
        memset(msgbuf, 0, sizeof(msgbuf));
        if((nbyte=L_Multicast_Util::receive(this->m_fd,msgbuf,size,this->m_addr))<0){
            //std::cerr<<"receive failed"<<std::endl;
    	}else{
            msg = new L_Message(msgbuf,size);
            this->m_queue.add(msg);
        }
    }
}
