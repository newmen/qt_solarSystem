#ifndef ORBIT_H
#define ORBIT_H

#include <QColor>
#include "iorbit.h"
#include "ishapefactory.h"

class Orbit : public IOrbit
{
public:
    Orbit(const IOrbit *parent, float orbitRaduis, const IShapeFactory *shapeFactory, float shapeRadius, const QColor &shapeColor);

protected:
    const IOrbit *parent() const { return _parent; }
    float radius() const { return _radius; }

private:
    const IOrbit *_parent;
    float _radius;
};

#endif // ORBIT_H
