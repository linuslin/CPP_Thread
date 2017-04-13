

#ifndef __L_THREAD_H__
#define __L_THREAD_H__

#include <pthread.h>
 
class L_Thread
{
  public:
    L_Thread();
    virtual ~L_Thread();
 
    virtual int start();
    virtual int join();
    virtual int detach();
    virtual pthread_t self();
 
    virtual void* run() = 0;
 
  private:
    pthread_t  m_tid;
    int        m_running;
    int        m_detached;
};

#endif
