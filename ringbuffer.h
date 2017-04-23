
#ifndef __L_RING_BUFFER__
#define __L_RING_BUFFER__

class L_RingBuffer 
{
    //unsigned int m_w_count;
    unsigned int m_count;
    unsigned int m_size;
    int m_head;
    int m_tail;
    double * m_array;

    void incCount();
    void decCount();
    void incIndex(int & index);
    void decIndex(int & index);

    public:
        L_RingBuffer(unsigned int size);
        ~L_RingBuffer();
    	bool isEmpty();
    	bool isFull();
    	int push(const double& data);
    	double pop();
    	void dump();
    	void clear();
};

#endif
