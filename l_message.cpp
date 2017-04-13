
#include "l_message.h"

L_Message::L_Message(unsigned char * msg, unsigned int len):m_msg(msg),m_len(len){
    //this->m_len=(len>MSGSIZE)? MSGSIZE:len;
}

void L_Message::setMsg(unsigned char * msg, unsigned int len)
{
    this->m_len=len;
    this->m_msg=msg;
}

