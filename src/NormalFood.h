#ifndef NORMAL_FOOD_H
#define NORMAL_FOOD_H

#include "food.h"
#include "snake.h"

//this food is yellow in color
class NormalFood : public Food{
    public:
    NormalFood(int x, int y);

    void ApplyEffect(Snake& snake)override;
};

#endif