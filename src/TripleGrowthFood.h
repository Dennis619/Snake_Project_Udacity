#ifndef TRIPPLE_GROWTH_FOOD_H
#define TRIPPLE_GROWTH_FOOD_H

#include "food.h"
#include "snake.h"

///this food is blue in color
class TripleGrowthFood : public Food{
    public:
    TripleGrowthFood(int x, int y);

    void ApplyEffect(Snake& snake) override;
};

#endif