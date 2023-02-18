#ifndef DRAWABLEOBJECT_H

#define DRAWABLEOBJECT_H

class Renderer;

class DrawableObject
{
public:
    virtual void draw(Renderer &renderer) = 0;
};

#endif