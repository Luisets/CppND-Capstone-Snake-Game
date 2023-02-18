#include "controller.h"
#include "enums.h"
#include "snake.h"
#include <SDL2/SDL.h>
#include <iostream>

void Controller::changeDirection(Snake &snake, SnakeDirection input,
                                 SnakeDirection opposite) const
{
  if (snake.getDirection() != opposite || snake.getSize() == 1)
  {
    snake.setDirection(input);
  }
}

void Controller::handleInput(bool &running, Snake &snake) const
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
        changeDirection(snake, SnakeDirection::kUp,
                        SnakeDirection::kDown);
        break;

      case SDLK_DOWN:
        changeDirection(snake, SnakeDirection::kDown,
                        SnakeDirection::kUp);
        break;

      case SDLK_LEFT:
        changeDirection(snake, SnakeDirection::kLeft,
                        SnakeDirection::kRight);
        break;

      case SDLK_RIGHT:
        changeDirection(snake, SnakeDirection::kRight,
                        SnakeDirection::kLeft);
        break;
      }
    }
  }
}
