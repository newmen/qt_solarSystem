#include "orbit.h"

Orbit::Orbit(const IOrbit *parent, float orbitRaduis, const IShapeFactory *shapeFactory, float shapeRadius, const QColor &shapeColor) :
    IOrbit(shapeFactory->makeShape(shapeRadius, shapeColor)), _parent(parent), _radius(orbitRaduis) {}
