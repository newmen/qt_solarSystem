#include <QGLViewer/qglviewer.h>
#include <cmath>
#include "sphere.h"

#define LATS 34
#define LONGS 34

Sphere::Sphere(float radius, const QColor &color) : Shape(radius, color) {}

void Sphere::drawShape(const float3 &center) const {
    for(int i = 0; i <= LATS; i++) {
        double lat0 = M_PI * (-0.5 + (double)(i - 1) / LATS);
        double z0  = sin(lat0) * radius();
        double zr0 =  cos(lat0);

        double lat1 = M_PI * (-0.5 + (double) i / LATS);
        double z1 = sin(lat1) * radius();
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(int j = 0; j <= LONGS; j++) {
            double lng = 2 * M_PI * (double)(j - 1) / LONGS;
            double x = cos(lng) * radius();
            double y = sin(lng) * radius();

            glNormal3f(center.x + x * zr0, center.y + y * zr0, center.z + z0);
            glVertex3f(center.x + x * zr0, center.y + y * zr0, center.z + z0);
            glNormal3f(center.x + x * zr1, center.y + y * zr1, center.z + z1);
            glVertex3f(center.x + x * zr1, center.y + y * zr1, center.z + z1);
        }
        glEnd();
    }
}
