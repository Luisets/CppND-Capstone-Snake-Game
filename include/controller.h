#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller
{
public:
    void handleInput(bool &running, Snake &snake) const;

private:
    void changeDirection(Snake &snake, SnakeDirection input,
                         SnakeDirection opposite) const;
};

#endif
