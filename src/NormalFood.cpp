#include "NormalFood.h"

#include<iostream>

NormalFood::NormalFood(int x, int y): Food(x, y){ color = {0xFF, 0xCC, 0x00, 0xFF}; }

void NormalFood::ApplyEffect(Snake& snake){
    std::cout << "Normal Food Create, size: "<< snake.GetSnakeSize() << std::endl;
    snake.SetSnakeSize(snake.GetSnakeSize() + 1);     
}