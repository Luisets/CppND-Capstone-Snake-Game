#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "snake.h"
#include <vector>

class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void render(Snake const snake, SDL_Point const &food);
  void updateWindowTitle(int score, int fps);
  void showScreen();
  void hideScreen();
  void closeScreen();

private:
  SDL_Window *_sdl_window;
  SDL_Renderer *_sdl_renderer;

  const std::size_t _screen_width;
  const std::size_t _screen_height;
  const std::size_t _grid_width;
  const std::size_t _grid_height;
};

#endif