#include "ringbuffer.h"

#include <iostream>

int main(){

    L_RingBuffer tmpbuf = L_RingBuffer(10);

    for (int i=0;i<20;i++){
        tmpbuf.push(i);        
        tmpbuf.dump();
    }
    for (int i=0;i<20;i++){
        std::cout<<tmpbuf.pop();        
        tmpbuf.dump();
    }
    return 0;
}
