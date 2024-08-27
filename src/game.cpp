#include "game.h"
#include <iostream>
#include<thread>
#include<chrono>
#include "SDL.h"
#include "NormalFood.h"
#include "DoubleGrowthFood.h"
#include "TripleGrowthFood.h"
#include "food.cpp"
#include "NormalFood.cpp"
#include "DoubleGrowthFood.cpp"
#include "TripleGrowthFood.cpp"
#include "PoisonFood.cpp"

Game::Game(std::size_t grid_width, std::size_t grid_height, GameDifficulty &levelDifficulty)
    : snake(grid_width, grid_height, levelDifficulty),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_foodType(0, 2) {
  PlaceFood();
  std::thread(&Game::ManagePoisonFood, this).detach();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, poison);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y, randType;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    randType = random_foodType(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      //select the type of food
      switch(randType){
      case 0:
        food = std::make_unique<NormalFood> (x, y);
        break;
      case 1:
        food = std::make_unique<DoubleGrowthFood> (x, y);
        break;
      case 2:
        food = std::make_unique<TripleGrowthFood> (x, y);
        break;
      default:
        std::cout<<"Invalid Food Option Choise!!" << std::endl;
        break;
      }
      //food.x = x;
      //food.y = y;
      return;
    }
  }
}

 void Game::PlacePoison(){
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    if (!snake.SnakeCell(x, y)) {
      poison = std::make_unique<PoisonFood> (x, y);
      return;
    }
  }
 };

 void Game::ManagePoisonFood(){
  while(true){
    std::this_thread::sleep_for(std::chrono::minutes(1));
    std::cout<<"Poison is"<<std::endl;
    PlacePoison();
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    poison.reset();
  }
 };

void Game::Update() {
  if (!snake.alive) return;

  //pass food for it to know how to update depending on the food
  snake.Update(food);

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food->GetPosX() == new_x && food->GetPosY() == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    //update size in the snake class depending on the food type
    snake.speed += 0.02;
  }

  //check if player ate poison
  if(poison && poison->GetPosX() == new_x && poison->GetPosY() == new_y){
    poison->ApplyEffect(snake);
    poison.reset();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.GetSnakeSize(); }