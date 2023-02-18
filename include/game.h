#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "obstacle.h"
#include "renderer.h"
#include "scoreboard.h"
#include "snake.h"
#include <SDL2/SDL.h>
#include <random>
#include <string>

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void initialize();
  void run(Renderer &renderer,
           std::size_t target_frame_duration);
  void displayScores();
  void checkAndUpdateScores();
  int getScore() const;
  int getSize() const;

private:
  Snake _snake;
  Obstacle _obstacle;
  Controller _controller;
  Scoreboard _scoreboard;
  SDL_Point _food;

  static constexpr char SCOREBOARD_PATH[] = "./scoreboard";

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int _score{0};

  void placeFood();
  void update();
};

#endif
