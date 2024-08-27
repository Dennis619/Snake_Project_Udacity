#include <iostream>
#include<string>
#include<memory>
#include "mainMenu.cpp"
#include "Player.h"

int main() {
  /*
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  */

  Player player;
  std::unique_ptr<MainMenu> mainMenu = std::make_unique<MainMenu>(std::move(player));
  mainMenu->StartMenu();

  return 0;
}