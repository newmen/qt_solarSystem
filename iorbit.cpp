#include "iorbit.h"

TimeCounter *IOrbit::__counter;

IOrbit::IOrbit(Shape *shape) : _shape(shape) {}

IOrbit::~IOrbit() {
    delete _shape;
    for (OrbitContainer::iterator p = _childs.begin(); p != _childs.end(); p++) {
        delete *p;
    }
}

void IOrbit::draw() const {
    _shape->draw(center());
    for (OrbitContainer::const_iterator p = _childs.begin(); p != _childs.end(); p++) {
        (*p)->draw();
    }
}

bool IOrbit::isFull() const {
    return _childs.size() > 5;
}

IOrbit *IOrbit::addChild(IOrbit *child) {
    _childs.push_back(child);
    return child;
}
