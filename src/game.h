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
  void initialize();
  void Run(Renderer &renderer,
           std::size_t target_frame_duration);
  void displayScores();
  void checkAndUpdateScores();
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Controller controller;
  Scoreboard _scoreboard;
  SDL_Point food;

  static constexpr char SCOREBOARD_PATH[] = "./scoreboard";

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int _score{0};

  void PlaceFood();
  void Update();
};

#endif