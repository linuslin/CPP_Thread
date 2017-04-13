#include "indexCaculator.h"

//IndexCaculator::IndexCaculator()
#include<iostream>
#include"bmpheader.h"

void* IndexCaculator::run(){
    for (int i = 0;; i++) {
        L_Message * msg = (L_Message *)this->m_queue.remove();
        std::cout<<"got one food\n"; 
        BMPHeader header((char *)msg->m_msg+1);
        header.dump();
        delete msg;
    }
}
