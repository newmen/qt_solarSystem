#include "sun.h"

Sun::Sun(const IShapeFactory *shapeFactory, float radius) :
    IOrbit(shapeFactory->makeShape(radius, Qt::yellow)), _center(float3(0.0, 0.0, 0.0)) {}

