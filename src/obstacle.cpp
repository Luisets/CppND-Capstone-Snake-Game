#include "obstacle.h"
#include "renderer.h"
#include "tuple"

Obstacle::Obstacle(int grid_width, int grid_height)
    : _grid_width(grid_width)
    , _grid_height(grid_height)
{
}

void Obstacle::draw(Renderer &renderer)
{
    SDL_Rect block;
    std::tie(block.w, block.h) = renderer.getBlockDimentions();
    renderer.setBrushColor(BrushColor::Obstacle);
    for (auto &point : _coordinates)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        renderer.drawBlock(block);
    }
}

void Obstacle::loadObstacles(Difficulty difficulty)
{
    _coordinates.clear();

    if(difficulty == Difficulty::Easy)
    {
        return;
    }

    SDL_Point coordinate;
    for(int i = 12; i < 24; ++i)
    {
        coordinate.x = i;
        coordinate.y = 15;
        _coordinates.emplace_back(coordinate);
    }

    for(int i = 8; i < 24; ++i)
    {
        coordinate.x = 12;
        coordinate.y = i;
        _coordinates.emplace_back(coordinate);
    }
}