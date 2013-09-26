#include <cmath>
#include "flatorbit.h"

FlatOrbit::FlatOrbit(const IOrbit *parent, float orbitRaduis, float rate,
                     const IShapeFactory *shapeFactory, float shapeRadius, const QColor &shapeColor) :
    // может быть вместо parent стоит использовать this
    Orbit(parent, orbitRaduis, shapeFactory, shapeRadius, shapeColor), _angle(2 * asin(rate * 0.5 / radius())) {}

float3 FlatOrbit::center() const {
    float3 newCenter = parent()->center();
    newCenter.x += radius() * cos(__counter->now() * _angle);
    newCenter.y += radius() * sin(__counter->now() * _angle);

    return newCenter;
}

