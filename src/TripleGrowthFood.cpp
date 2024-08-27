#include "TripleGrowthFood.h"

TripleGrowthFood::TripleGrowthFood(int x, int y): Food(x, y){ color = {0x00, 0x00, 0xFF, 0xFF}; }

void TripleGrowthFood::ApplyEffect(Snake& snake) {
    std::cout << "Triple Growth Food Create, size: " << snake.GetSnakeSize() << std::endl;
    snake.SetSnakeSize(snake.GetSnakeSize() + 3); 
}