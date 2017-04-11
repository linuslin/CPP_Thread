#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "l_thread.h"
 
class MyThread : public L_Thread
{
  public:
    void *run() {
        for (int i = 0; i < 5; i++) {
            printf("thread %lu running - %d\n",  (long unsigned int)self(), i+1);
            usleep(100);
        }
        printf("thread done %lu\n", (long unsigned int)self());
        return NULL;
    }
};


int main(int argc, char** argv)
{
    MyThread* thread1 = new MyThread();
    MyThread* thread2 = new MyThread();
    thread1->start();
    thread2->start();
    thread1->join();
    thread2->join();
    printf("main done\n");
    exit(0);
}
