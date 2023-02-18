#include "game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : _snake(grid_width, grid_height)
    , _scoreboard(Game::SCOREBOARD_PATH)
    , engine(dev())
    , random_w(0, static_cast<int>(grid_width - 1))
    , random_h(0, static_cast<int>(grid_height - 1))
{
  placeFood();
}
void Game::initialize()
{
  _snake.initialize();
  _score = 0;
}
void Game::run(Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  renderer.showScreen();
  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    _controller.handleInput(running, _snake);
    update();
    renderer.render(_snake, _food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.updateWindowTitle(_score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }

    running = _snake.isAlive();
  }
  renderer.hideScreen();
}

void Game::placeFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!_snake.snakeCell(x, y))
    {
      _food.x = x;
      _food.y = y;
      return;
    }
  }
}

void Game::update()
{
  if (!_snake.isAlive())
    return;

  _snake.update();

  int new_x = static_cast<int>(_snake.getHead_x());
  int new_y = static_cast<int>(_snake.getHead_y());

  // Check if there's food over here
  if (_food.x == new_x && _food.y == new_y)
  {
    _score++;
    placeFood();
    // Grow snake and increase speed.
    _snake.growBody();
    _snake.speedUp();
  }
}

void Game::checkAndUpdateScores()
{
  _scoreboard.updateScoreboard(_score);
}

int Game::getScore() const { return _score; }
int Game::getSize() const { return _snake.getSize(); }
void Game::displayScores() { _scoreboard.displayScoreboard(); }