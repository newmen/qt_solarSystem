#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"

class Sphere : public Shape
{
public:
    Sphere(float radius, const QColor &color);

protected:
    void drawShape(const float3 &center) const;
};

#endif // SPHERE_H
