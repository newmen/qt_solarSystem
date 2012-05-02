#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "ishapefactory.h"

template <class TShape>
class ShapeFactory : public IShapeFactory {
public:
    Shape *makeShape(float radius, const QColor &color) const {
        return new TShape(radius, color);
    }
};

#endif // SHAPEFACTORY_H
