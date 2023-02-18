#include "snake.h"
#include "renderer.h"
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>

Snake::Snake(int grid_width, int grid_height)
    : _grid_width(grid_width)
    , _grid_height(grid_height)
    , _head_x(grid_width / 2)
    , _head_y(grid_height / 2)
{
}

void Snake::initialize()
{
  _direction = SnakeDirection::kNone;
  _head_x = _grid_width / 2;
  _head_y = _grid_height / 2;
  _speed = 0.1;
  _size = 2;
  _alive = true;
  _body.clear();
}

void Snake::update()
{
  SDL_Point prev_cell{
      static_cast<int>(_head_x),
      static_cast<int>(
          _head_y)}; // We first capture the head's cell before updating.
  updateHead();
  SDL_Point current_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)}; // Capture the head's cell after updating.

  // update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    updateBody(current_cell, prev_cell);
  }
}

void Snake::updateHead()
{
  switch (_direction)
  {
  case SnakeDirection::kUp:
    _head_y -= _speed;
    break;

  case SnakeDirection::kDown:
    _head_y += _speed;
    break;

  case SnakeDirection::kLeft:
    _head_x -= _speed;
    break;

  case SnakeDirection::kRight:
    _head_x += _speed;
    break;

  case SnakeDirection::kNone:
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  _head_x = fmod(_head_x + _grid_width, _grid_width);
  _head_y = fmod(_head_y + _grid_height, _grid_height);
}

void Snake::updateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
  // Add previous head location to vector
  _body.push_back(prev_head_cell);

  if (!_growing)
  {
    // Remove the tail from the vector.
    _body.erase(_body.begin());
  }
  else
  {
    _growing = false;
    _size++;
  }

  checkCollision(_body);
}

void Snake::growBody() { _growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::snakeCell(int x, int y)
{
  if (x == static_cast<int>(_head_x) && y == static_cast<int>(_head_y))
  {
    return true;
  }
  for (auto const &item : _body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}

void Snake::checkCollision(const std::vector<SDL_Point> &points)
{
  int cellHead_x = static_cast<int>(_head_x);
  int cellHead_y = static_cast<int>(_head_y);
  for (auto &point : points)
  {
    if (cellHead_x == point.x && cellHead_y == point.y)
    {
      _alive = false;
      break;
    }
  }
}

void Snake::render(Renderer &renderer)
{
  SDL_Rect block;
  std::tie(block.w, block.h) = renderer.getBlockDimentions();

  // Render snake's body
  renderer.setBrushColor(BrushColor::SnakeBody);
  for (SDL_Point const &point : _body)
  {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    renderer.render(block);
  }

  // Render snake's head
  block.x = static_cast<int>(_head_x) * block.w;
  block.y = static_cast<int>(_head_y) * block.h;
  if (isAlive())
  {
    renderer.setBrushColor(BrushColor::SnakeHeadAlive);
  }
  else
  {
    renderer.setBrushColor(BrushColor::SnakeHeadDead);
  }
  renderer.render(block);
}

void Snake::speedUp()
{
  _speed += 0.02;
}
