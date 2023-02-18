#include "controller.h"
#include <SDL2/SDL.h>
#include "snake.h"
#include <iostream>

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const
{
  if (snake.getDirection() != opposite || snake.getSize() == 1)
  {
    snake.setDirection(input);
  }
}

void Controller::HandleInput(bool &running, Snake &snake) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        ChangeDirection(snake, Snake::Direction::kUp,
                        Snake::Direction::kDown);
        break;

      case SDLK_DOWN:
        ChangeDirection(snake, Snake::Direction::kDown,
                        Snake::Direction::kUp);
        break;

      case SDLK_LEFT:
        ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
        break;

      case SDLK_RIGHT:
        ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
        break;
      }
    }
  }
}