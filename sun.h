#ifndef SUN_H
#define SUN_H

#include "iorbit.h"
#include "ishapefactory.h"

class Sun : public IOrbit
{
public:
    Sun(const IShapeFactory *shapeFactory, float radius);

    float3 center() const { return _center; }

private:
    float3 _center;
};

#endif // SUN_H
