#include "l_multicast.h"

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
    if((result=L_Multicast_Util::connect(this->m_group,this->m_port,this->m_addr,errorMsg))<0){
        std::cout<<"setup connection failed\n";
        return -1; 
    }else{
        return this->L_Thread::start();
    }
}


void* L_Multicast::run(){
    int result,fd=0;
    ssize_t nbyte;
    L_Message * msg;
    int size = BUFFERSIZE;
    char msgbuf[size];

    while(1){ // need to add condition var
        if((nbyte=L_Multicast_Util::receive(fd,msgbuf,size,this->m_addr))<0){
        std::cerr<<"receive failed"<<std::endl;
    	}else{
            puts(msgbuf);
            BMPHeader header(msgbuf+1);
            header.dump();
            //msg = new L_Message("apple", 123);
            //queue.add();
        }
    }
}
