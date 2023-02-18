#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : _screen_width(screen_width)
    , _screen_height(screen_height)
    , _grid_width(grid_width)
    , _grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  _sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, _screen_width,
                                 _screen_height, SDL_WINDOW_HIDDEN);

  if (nullptr == _sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  _sdl_renderer = SDL_CreateRenderer(_sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == _sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(_sdl_window);
  SDL_Quit();
}

void Renderer::cleanScreen()
{
  // Clear screen
  setBrushColor(BrushColor::BackGround);
  SDL_RenderClear(_sdl_renderer);
}

void Renderer::render(SDL_Rect &block)
{
  SDL_RenderFillRect(_sdl_renderer, &block);
}

void Renderer::setBrushColor(const BrushColor color)
{
  switch (color)
  {
  case BrushColor::BackGround:
    SDL_SetRenderDrawColor(_sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    break;
  case BrushColor::Food:
    SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    break;
  case BrushColor::Obstacle:
    SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    break;
  case BrushColor::SnakeBody:
    SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    break;
  case BrushColor::SnakeHeadAlive:
    SDL_SetRenderDrawColor(_sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    break;
  case BrushColor::SnakeHeadDead:
    SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    break;
  default:
    break;
  }
}

void Renderer::updateScreen()
{
  SDL_RenderPresent(_sdl_renderer);
}

void Renderer::updateWindowTitle(int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(_sdl_window, title.c_str());
}

void Renderer::showScreen()
{
  SDL_ShowWindow(_sdl_window);
}

void Renderer::hideScreen()
{
  SDL_HideWindow(_sdl_window);
}
