#include "food.h"

Food::Food(const char* message, int number) : m_food(message), m_number(number) {}
Food::~Food() {}
const char* Food::getFood() { return m_food.c_str(); }
int Food::getNumber() { return m_number; }

