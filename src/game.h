#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "GameDifficulty.h"
#include "food.h"

#include<memory>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, GameDifficulty &levelDifficulty);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  //std::unique_ptr<Snake> snake;
  Snake snake;
  std::unique_ptr<Food> food;
  std::unique_ptr<Food> poison;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_int_distribution<int> random_foodType;

  int score{0};

  void PlaceFood();
  void PlacePoison();
  void ManagePoisonFood();
  void Update();
};

#endif