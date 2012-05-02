#include <QtGui>
#include "mainwindow.h"
#include "shapefactory.h"
#include "sphere.h"
#include "cube.h"

MainWindow::MainWindow() {
    _solarSystem = new SolarSystem(this, new ShapeFactory<Sphere>);
    _solarSystem->init();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(_solarSystem);

    setLayout(layout);
}

MainWindow::~MainWindow() {
    delete _solarSystem;
}
