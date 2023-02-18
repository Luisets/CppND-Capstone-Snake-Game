#ifndef OBSTACLE_H

#define OBSTACLE_H

#include "SDL2/SDL.h"
#include "drawableObject.h"
#include "enums.h"
#include <vector>

class Obstacle : virtual public DrawableObject
{
public:
    Obstacle(int grid_width, int grid_height);
    void draw(Renderer &renderer) override;
    void loadObstacles(Difficulty difficulty);
    bool checkCell(int x, int y);

    const std::vector<SDL_Point> &getPoints() const { return _coordinates; };

private:
    std::vector<SDL_Point> _coordinates;

    int _grid_width;
    int _grid_height;
};
#endif