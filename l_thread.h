#include <pthread.h>
 
class L_Thread
{
  public:
    L_Thread();
    virtual ~L_Thread();
 
    int start();
    int join();
    int detach();
    pthread_t self();
 
    virtual void* run() = 0;
 
  private:
    pthread_t  m_tid;
    int        m_running;
    int        m_detached;
};