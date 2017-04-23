
#include "ringbuffer.h"

#include <iostream>
#include <string>


void L_RingBuffer::incIndex(int & index){
    index=(index+1) % this->m_size;
}

void L_RingBuffer::decIndex(int & index){
    index=(index + this-> m_size - 1) % this->m_size;
}

void L_RingBuffer::incCount(){
    if(this->m_size > this->m_count)
    	this->m_count++;
}

void L_RingBuffer::decCount(){
    if(this->m_count > 0)
        this->m_count--;
}


L_RingBuffer::L_RingBuffer(unsigned int size):m_size(size){
    this->m_count=this->m_tail=this->m_head=0;
    this->m_array = new double[size];
}

L_RingBuffer::~L_RingBuffer(){
    delete [] m_array;
}

bool L_RingBuffer::isEmpty()
{
    return (this->m_head==this->m_tail && this->m_count==0) ;
}

bool L_RingBuffer::isFull(){
    return (this->m_head==this->m_tail && this->m_count==this->m_size);
}

int L_RingBuffer::push(const double& data){

    if(this->isFull()){
        this->m_array[this->m_head]=data;
        this->incIndex(this->m_head);
        this->incIndex(this->m_tail);
    }else{
    	this->incCount();
    	this->m_array[this->m_tail]=data;
    	this->incIndex(this->m_tail);
    }
    return this->isFull();
}

double L_RingBuffer::pop(){
    if(this->isEmpty()){
	return -1;
    }
    double tmp = m_array[m_head];
    this->decCount();
    this->incIndex(this->m_head);
    return tmp;
}

void L_RingBuffer::dump(){
    std::cout<<"["; 
    if(this->m_count==0){
        std::cout<<" ]"<<std::endl;
        return; 
    }
    int p=this->m_head;
    if(this->m_count==this->m_size){
        std::cout<<this->m_array[p]<<" ";
        p = (p + 1)%this->m_size;
    }
    while(p!=this->m_tail){
        std::cout<<this->m_array[p]<<" ";
        p = (p + 1)%this->m_size;
    }
    std::cout<<"]"<<std::endl;
}

void L_RingBuffer::clear(){

}
