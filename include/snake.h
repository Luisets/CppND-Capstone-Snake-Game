#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <vector>

class Snake
{
public:
  enum class Direction
  {
    kUp,
    kDown,
    kLeft,
    kRight,
    kNone
  };

  Snake(int grid_width, int grid_height);

  void initialize();
  void update();

  void growBody();
  void speedUp();
  bool snakeCell(int x, int y);

  inline Direction getDirection() const { return _direction; }
  inline float getHead_x() const { return _head_x; }
  inline float getHead_y() const { return _head_y; }
  inline int getSize() const { return _size; }
  inline const std::vector<SDL_Point> &getBody() const { return _body; }
  inline bool isAlive() const { return _alive; }
  inline void setDirection(const Direction direction) { _direction = direction; }

private:
  void updateHead();
  void updateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  Direction _direction = Direction::kNone;
  std::vector<SDL_Point> _body;

  bool _alive{true};
  bool _growing{false};
  float _head_x;
  float _head_y;
  int _grid_width;
  int _grid_height;

  float _speed{0.1f};
  int _size{1};
};

#endif