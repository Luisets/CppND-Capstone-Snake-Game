#ifndef RENDERABLEOBJECT_H

#define RENDERABLEOBJECT_H

class Renderer;

class RenderableObject
{
public:
    virtual void render(Renderer &renderer) = 0;
};

#endif