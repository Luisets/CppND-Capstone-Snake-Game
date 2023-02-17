#include "snake.h"
#include <cmath>
#include <iostream>

Snake::Snake(int grid_width, int grid_height)
    : _grid_width(grid_width)
    , _grid_height(grid_height)
    , _head_x(grid_width / 2)
    , _head_y(grid_height / 2)
{
}

void Snake::initialize()
{
  _direction = Direction::kNone;
  _head_x = _grid_width / 2;
  _head_y = _grid_height / 2;
  _speed = 0.1;
  _size = 2;
  _alive = true;
  _body.clear();
}

void Snake::Update()
{
  SDL_Point prev_cell{
      static_cast<int>(_head_x),
      static_cast<int>(
          _head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)}; // Capture the head's cell after updating.

  // Update all of the _body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead()
{
  switch (_direction)
  {
  case Direction::kUp:
    _head_y -= _speed;
    break;

  case Direction::kDown:
    _head_y += _speed;
    break;

  case Direction::kLeft:
    _head_x -= _speed;
    break;

  case Direction::kRight:
    _head_x += _speed;
    break;

  case Direction::kNone:
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  _head_x = fmod(_head_x + _grid_width, _grid_width);
  _head_y = fmod(_head_y + _grid_height, _grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
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

  // Check if the snake has died.
  for (auto const &item : _body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      _alive = false;
    }
  }
}

void Snake::GrowBody() { _growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
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

void Snake::speedUp()
{
  _speed += 0.2;
}