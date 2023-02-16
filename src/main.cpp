#include <iostream>
#include <cstring>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "scoreboard.h"

// #define SCOREBOARD_PATH "./scoreboard"

void displayMenu();

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  // Scoreboard scoreboard(SCOREBOARD_PATH);
  // std::string line;
  // while(true)
  // {
    
  //   displayMenu();
  //   std::cout << "Chose your option: ";
  //   std::getline(std::cin, line);
  //   if (line == "2")
  //   {
  //     scoreboard.displayScoreboard();
  //   }
  //   else if (line == "3")
  //   {
  //     break;
  //   }

  //   else if (line == "test")
  //   {
  //     std::string nick;
  //     unsigned long score;
  //     std::cin >> nick >> score;
  //     std::cin.ignore();
  //     score_entry entry;
  //     // std::strcpy(entry.nickname, nick.c_str());
  //     nick.copy(entry.nickname, 10);
  //     entry.nickname[10] = '\0';
  //     entry.score = score;
  //     scoreboard.updateScoreboard(entry);
  //   }
  // }
  // std::cout << "Thanks for playing!!" << std::endl;
  return 0;
}

void displayMenu()
{
  std::cout << "\t---- Options menu ----" << std::endl;
  std::cout << "\t 1.- Play" << std::endl;
  std::cout << "\t 2.- Scoreboar" << std::endl;
  std::cout << "\t 3.- Exit" << std::endl;
}