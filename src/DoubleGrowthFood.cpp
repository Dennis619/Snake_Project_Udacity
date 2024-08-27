#include "DoubleGrowthFood.h"

DoubleGrowthFood::DoubleGrowthFood(int x, int y): Food(x, y){ color = {0xFF, 0x00, 0x00, 0xFF}; }

void DoubleGrowthFood::ApplyEffect(Snake& snake){
    std::cout << "Double Growth Food Create, size: " << snake.GetSnakeSize() << std::endl;
    snake.SetSnakeSize(snake.GetSnakeSize() + 2); 
}