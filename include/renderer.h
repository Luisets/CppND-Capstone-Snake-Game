#ifndef RENDERER_H
#define RENDERER_H

#include "snake.h"
#include <SDL2/SDL.h>
#include <utility>
#include <vector>

class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void updateWindowTitle(int score, int fps);
  void cleanScreen();
  void updateScreen();
  void render(SDL_Rect &block);
  void setBrushColor(const BrushColor color);
  void showScreen();
  void hideScreen();
  void closeScreen();

  inline std::pair<int, int> getBlockDimentions() { return std::make_pair((_screen_width / _grid_width), (_screen_height / _grid_height)); }

private:
  SDL_Window *_sdl_window;
  SDL_Renderer *_sdl_renderer;

  const std::size_t _screen_width;
  const std::size_t _screen_height;
  const std::size_t _grid_width;
  const std::size_t _grid_height;
};

#endif
