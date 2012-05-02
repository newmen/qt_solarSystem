#ifndef FLATORBIT_H
#define FLATORBIT_H

#include "orbit.h"

class FlatOrbit : public Orbit
{
public:
    FlatOrbit(const IOrbit *parent, float orbitRaduis, float rate,
              const IShapeFactory *shapeFactory, float shapeRadius, const QColor &shapeColor);

    float3 center() const;

private:
    float _angle;
};

#endif // FLATORBIT_H
