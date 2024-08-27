#ifndef POISON_FOOD_H
#define POISON_FOOD_H

#include "food.h"
#include "snake.h"
#include <chrono>

//this food is green in color
class PoisonFood : public Food{
    public:
    PoisonFood(int x, int y);

    void ApplyEffect(Snake &snake) override;

    private:
    std::chrono::high_resolution_clock::time_point start;
};

#endif