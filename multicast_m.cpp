
#include "l_m_queue.h"
#include "l_message.h"
#include "l_multicast.h"
#include "l_thread.h"
#include <unistd.h>
#include "indexCaculator.h"




int main(){
     L_M_Queue<L_Message*>  queue;
     char group[]="225.0.0.37";
     L_Multicast * zzz = new L_Multicast(queue,"TWSE",group,12345);
     zzz->start();
     IndexCaculator * xxx = new IndexCaculator(queue,"XXX");
     xxx->start();
     sleep(1);
     while (1);
     exit(0);

     return 0;
}
