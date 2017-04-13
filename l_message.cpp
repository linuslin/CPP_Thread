#include <cstring>
#include <string.h>
#include "l_message.h"
#include <iostream>

L_Message::L_Message(unsigned char * msg, unsigned int len):m_len(len){
     //strlcpy(this->m_msg,msg,sizeof(this->m_msg));
     memcpy(this->m_msg,msg,len);
     //this->m_len=(len>MSGSIZE)? MSGSIZE:len;
}

void L_Message::setMsg(unsigned char * msg, unsigned int len)
{
    this->m_len=len;
    //strlcpy(this->m_msg,msg,sizeof(this->m_msg));
    memcpy(this->m_msg,msg,len);
}

L_Message::~L_Message(){
}
