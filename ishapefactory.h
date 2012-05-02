#ifndef ISHAPEFACTORY_H
#define ISHAPEFACTORY_H

#include "shape.h"

class IShapeFactory {
public:
    virtual Shape *makeShape(float radius, const QColor &color) const = 0;
};

#endif // ISHAPEFACTORY_H
