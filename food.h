
#ifndef __FOOD__
#define __FOOD__

#include <stdio.h>
#include <stdlib.h>
#include <string>

// ===============

#include "../l_thread.h"
#include "l_m_queue.h"

// ===============

 
class Food
{
    std::string m_food;
    int    m_number;

  public:
    Food(const char* message, int number);
    ~Food();
 
    const char* getFood();
    int getNumber();
};


#endif
