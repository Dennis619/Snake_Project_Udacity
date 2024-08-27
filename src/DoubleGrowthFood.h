#ifndef DOUBLE_GROWTH_FOOD_H
#define DOUBLE_GROWTH_FOOD_H

#include "food.h"
#include "snake.h"

//this food is red in color
class DoubleGrowthFood : public Food{
    public:
    DoubleGrowthFood(int x, int y);

    void ApplyEffect(Snake& snake)override;
};

#endif