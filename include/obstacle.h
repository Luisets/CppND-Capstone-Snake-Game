#ifndef OBSTACLE_H

#define OBSTACLE_H

#include <vector>
#include "SDL2/SDL.h"
#include "drawableObject.h"

class Obstacle : virtual public DrawableObject
{
public:
    Obstacle(int grid_width, int grid_height);
    ~Obstacle();
    void draw(Renderer &renderer) override;

    const std::vector<SDL_Point> &getPoints() const { return _coordinates; };

private:
    std::vector<SDL_Point> _coordinates;

    int _grid_width;
    int _grid_height;
};
#endif