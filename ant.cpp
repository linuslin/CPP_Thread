
#include "food.h"
#include <unistd.h>

class QueenAnt : public L_Thread
{
    L_M_Queue<Food*>& m_queue;
    std::string _name;
 
  public:
    QueenAnt(L_M_Queue<Food*>& queue,std::string name) : m_queue(queue),_name(name) {}
 
    void* run() {
        // Eat 1 food at a time. Blocks if no foods.
        for (int i = 0;; i++) {
            printf("thread %lu %s, loop %d - waiting for food...\n", 
                  (long unsigned int)self(), this->_name.c_str(), i);
            Food* food = (Food*)m_queue.remove();
            printf("thread %lu %s, loop %d - got one food\n", 
                  (long unsigned int)self(),this->_name.c_str() , i);
            printf("thread %lu %s, loop %d - food: food - %s, number - %d\n", 
                  (long unsigned int)self(),this->_name.c_str() , i, food->getFood(), 
                   food->getNumber());
            delete food;
        }
        return NULL;
    }
};


int main(int argc, char** argv)
{
    // Process command line arguments
    if ( argc != 2 ) {
        printf("usage: %s <iterations>\n", argv[0]);
        exit(-1);
    }
    int iterations = atoi(argv[1]);
 
    // Create the queue and consumer (worker) threads
    L_M_Queue<Food*>  queue;
    QueenAnt* queen1 = new QueenAnt(queue,"Red");
    QueenAnt* queen2 = new QueenAnt(queue,"Blue");
    queen1->start();
    queen2->start();
 
    // Add foods to the queue
    Food* food;
    for (int i = 0; i < iterations; i++) {
        food = new Food("apple", 123);
        queue.add(food);
        food = new Food("orange", 456);
        queue.add(food);
        food = new Food("candy", 789);
        queue.add(food);
        usleep(500000);
    }
 
    // Ctrl-C to end program
    sleep(1);
    printf("Enter Ctrl-C to end the program...\n");
    while (1);
    exit(0);
}
