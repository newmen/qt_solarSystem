#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include "common.h"

class Shape
{
public:
    Shape(float radius, const QColor &color);

    void draw(const float3 &center) const;

protected:
    virtual void drawShape(const float3 &center) const = 0;

    float radius() const { return _radius; }

private:
    float _radius;
    QColor _color;
};

#endif // SHAPE_H
