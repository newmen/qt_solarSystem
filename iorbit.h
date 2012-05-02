#ifndef IORBIT_H
#define IORBIT_H

#include <vector>
#include "common.h"
#include "shape.h"
#include "timecounter.h"

class IOrbit;

typedef std::vector<IOrbit *> OrbitContainer;

class IOrbit
{
public:
    static void setTimeCounter(TimeCounter *counter) {
        __counter = counter;
    }

    IOrbit(Shape *shape);
    ~IOrbit();

    virtual float3 center() const = 0;
    void draw() const;

    bool isFull() const;
    IOrbit *addChild(IOrbit *child);

protected:
    static TimeCounter *__counter;

private:
    const Shape *_shape;
    OrbitContainer _childs;
};

#endif // IORBIT_H
