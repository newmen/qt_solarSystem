#include <QGLViewer/qglviewer.h>
#include "cube.h"

Cube::Cube(float radius, const QColor &color) : Shape(radius, color) {}

void Cube::drawShape(const float3 &center) const {
    drawCube(center);
    drawBorder(center);
}

void Cube::drawCube(const float3 &center) const {
    float r = radius() * 0.5;

    glBegin(GL_QUADS);
    glVertex3f(center.x + r, center.y + r, center.z + r);
    glVertex3f(center.x + r, center.y - r, center.z + r);
    glVertex3f(center.x - r, center.y - r, center.z + r);
    glVertex3f(center.x - r, center.y + r, center.z + r);

    glVertex3f(center.x + r, center.y + r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y + r, center.z - r);

    glVertex3f(center.x + r, center.y + r, center.z + r);
    glVertex3f(center.x + r, center.y + r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z + r);

    glVertex3f(center.x - r, center.y + r, center.z + r);
    glVertex3f(center.x - r, center.y + r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z + r);

    glVertex3f(center.x + r, center.y + r, center.z + r);
    glVertex3f(center.x + r, center.y + r, center.z - r);
    glVertex3f(center.x - r, center.y + r, center.z - r);
    glVertex3f(center.x - r, center.y + r, center.z + r);

    glVertex3f(center.x + r, center.y - r, center.z + r);
    glVertex3f(center.x + r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z + r);
    glEnd();
}

void Cube::drawBorder(const float3 &center) const {
    float r = radius() * 0.55;

    glColor3f(0.35, 0.35, 0.35);
    glLineWidth(1.5);

    glBegin(GL_LINE_LOOP);
    glVertex3f(center.x + r, center.y + r, center.z + r);
    glVertex3f(center.x + r, center.y + r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z + r);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(center.x - r, center.y + r, center.z + r);
    glVertex3f(center.x - r, center.y + r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z + r);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(center.x + r, center.y + r, center.z + r);
    glVertex3f(center.x - r, center.y + r, center.z + r);
    glVertex3f(center.x + r, center.y + r, center.z - r);
    glVertex3f(center.x - r, center.y + r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z - r);
    glVertex3f(center.x - r, center.y - r, center.z - r);
    glVertex3f(center.x + r, center.y - r, center.z + r);
    glVertex3f(center.x - r, center.y - r, center.z + r);
    glEnd();
}


