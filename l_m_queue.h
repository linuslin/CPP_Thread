#ifndef __L_M_Queue__
#define __L_M_Queue__

#include <pthread.h>
#include <list>

template <typename T> class L_M_Queue
{ 
    std::list<T>   m_queue;
    pthread_mutex_t mq_mutex;
    pthread_cond_t  mq_cond;
public:
    L_M_Queue(){
        pthread_mutex_init(&mq_mutex, NULL);
        pthread_cond_init(&mq_cond, NULL);
    }
    ~L_M_Queue(){
        pthread_mutex_destroy(&mq_mutex);
        pthread_cond_destroy(&mq_cond);
    }
    void add(T item){
        pthread_mutex_lock(&mq_mutex);
        m_queue.push_back(item);
        pthread_cond_signal(&mq_cond);
        pthread_mutex_unlock(&mq_mutex);
    }
    T remove(){
        pthread_mutex_lock(&mq_mutex);
        while(m_queue.size() == 0) {
            pthread_cond_wait(&mq_cond, &mq_mutex);
        }
        T item = m_queue.front();
        m_queue.pop_front();
        pthread_mutex_unlock(&mq_mutex);
        return item;
    }
    int size(){
        pthread_mutex_lock(&mq_mutex);
        int size = m_queue.size();
        pthread_mutex_unlock(&mq_mutex);
        return size;
    }
};

#endif
