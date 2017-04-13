

#ifndef __INDEX_CACULATOR_H__
#define __INDEX_CACULATOR_H__

#include "l_thread.h"
#include "l_m_queue.h"
#include "l_message.h"
#include <unistd.h>
#include <string>

class IndexCaculator: public L_Thread
{
     L_M_Queue<L_Message*>& m_queue;
     std::string _name;

   public:
     
     IndexCaculator(L_M_Queue<L_Message*>& queue,std::string name) : m_queue(queue),_name(name) {}
     virtual void* run();

};

#endif
