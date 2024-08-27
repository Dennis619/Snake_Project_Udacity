#include "PoisonFood.h"


PoisonFood::PoisonFood(int x, int y): Food(x, y){ 
    color = {0x00, 0xFF, 0x00, 0xFF}; 
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Poison create" << std::endl;
    }

void PoisonFood::ApplyEffect(Snake &snake) {
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if(duration > std::chrono::milliseconds(1000)){ snake.alive = false; }   
}