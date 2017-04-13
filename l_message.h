

#ifndef __L_MESSAGE_H__
#define __L_MESSAGE_H__

struct L_Message
{
    static const int MSGSIZE=256;
    unsigned char m_msg[MSGSIZE];
    //unsigned char* m_msg;
    unsigned int m_len;

    L_Message(unsigned char * msg, unsigned int len);
    ~L_Message();
    
    void setMsg(unsigned char * msg, unsigned int len);
};
#endif
