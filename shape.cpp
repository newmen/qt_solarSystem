#include "shape.h"
#include <QGLViewer/qglviewer.h>

Shape::Shape(float radius, const QColor &color) : _radius(radius), _color(color) {}

void Shape::draw(const float3 &center) const {
    glColor3f(_color.redF(), _color.greenF(), _color.blueF());
    drawShape(center);
}
