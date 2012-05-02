#ifndef CUBE_H
#define CUBE_H

#include "shape.h"

class Cube : public Shape
{
public:
    Cube(float radius, const QColor &color);

protected:
    void drawShape(const float3 &center) const;

private:
    void drawCube(const float3 &center) const;
    void drawBorder(const float3 &center) const;
};

#endif // CUBE_H
