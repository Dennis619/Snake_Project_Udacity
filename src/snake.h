#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "GameDifficulty.h"
#include "food.h"
#include <memory>

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height, GameDifficulty &levelDifficulty)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        speed(levelDifficulty.GetGameSpeed()) {}

  void Update(std::unique_ptr <Food>& food);

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  //getter and setter snake's size
  int GetSnakeSize() const;
  void SetSnakeSize(int);

 private:
  int size{1};
  void UpdateHead();
  void UpdateBody(std::unique_ptr <Food>& food, SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif