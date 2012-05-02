#include "timecounter.h"

TimeCounter::TimeCounter(QWidget *parent) : _parent(parent), _counter(0) {
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(tick()));
    _timer->start(50);
}

TimeCounter::~TimeCounter() {
    delete _timer;
}

void TimeCounter::tick() {
    ++_counter;

    _parent->repaint();
}
