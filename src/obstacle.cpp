#include "obstacle.h"
#include "renderer.h"
#include "tuple"

Obstacle::Obstacle(int grid_width, int grid_height)
    : _grid_width(grid_width)
    , _grid_height(grid_height)
{
    SDL_Point coordinate;
    for(int i = 12; i < 24; ++i)
    {
        coordinate.x = i;
        coordinate.y = 15;
        _coordinates.emplace_back(coordinate);
    }
    
}

Obstacle::~Obstacle()
{
}

void Obstacle::render(Renderer &renderer)
{
    SDL_Rect block;
    std::tie(block.w, block.h) = renderer.getBlockDimentions();
    renderer.setBrushColor(BrushColor::Obstacle);
    for (auto &point : _coordinates)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        renderer.render(block);
    }
}