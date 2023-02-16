#ifndef GAME_H
#define GAME_H

#include <string>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "scoreboard.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void displayScores();
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Scoreboard _scoreboard;
  SDL_Point food;

  static constexpr char SCOREBOARD_PATH[] = "./scoreboard";

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif