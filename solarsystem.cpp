#include "solarsystem.h"
#include "sun.h"
#include "flatorbit.h"

SolarSystem::SolarSystem(QWidget *parent, IShapeFactory *shapeFactory) : QGLViewer(parent), _shapeFactory(shapeFactory) {
    _counter = new TimeCounter(this);
    IOrbit::setTimeCounter(_counter);

    _sun = new Sun(_shapeFactory, 34);

    IOrbit *redPlanet = _sun->addChild(new FlatOrbit(_sun, 55, 1, _shapeFactory, 2.8, Qt::red));
    IOrbit *nearSatellite = redPlanet->addChild(new FlatOrbit(redPlanet, 5, 1.5, _shapeFactory, 1, Qt::darkBlue));
    nearSatellite->addChild(new FlatOrbit(nearSatellite, 2.2, 1, _shapeFactory, 0.5, Qt::white));

    IOrbit *greenPlanet = _sun->addChild(new FlatOrbit(_sun, 89, 1.85, _shapeFactory, 8, Qt::green));
    greenPlanet->addChild(new FlatOrbit(greenPlanet, 12, 1, _shapeFactory, 1.5, Qt::white));
    IOrbit *twoStatelete = greenPlanet->addChild(new FlatOrbit(greenPlanet, 17, 0.3, _shapeFactory, 2, Qt::darkYellow));
    twoStatelete->addChild(new FlatOrbit(twoStatelete, 2.5, 0.34, _shapeFactory, 0.6, Qt::darkCyan));
    greenPlanet->addChild(new FlatOrbit(greenPlanet, 22, 1.3, _shapeFactory, 1, Qt::white));

    IOrbit *darkPlanet = _sun->addChild(new FlatOrbit(_sun, 144, 0.5, _shapeFactory, 5, Qt::darkMagenta));
    darkPlanet->addChild(new FlatOrbit(darkPlanet, 8, 0.5, _shapeFactory, 1, Qt::darkBlue));
    IOrbit *farSatellite = darkPlanet->addChild(new FlatOrbit(darkPlanet, 23, 0.2, _shapeFactory, 1.5, Qt::darkGray));
    farSatellite->addChild(new FlatOrbit(farSatellite, 3, 0.55, _shapeFactory, 0.8, Qt::lightGray));

    _sun->addChild(new FlatOrbit(_sun, 199, 1.5, _shapeFactory, 2, Qt::white));
}

SolarSystem::~SolarSystem() {
    delete _sun;
    delete _shapeFactory;

    delete _counter;
}

void SolarSystem::init() {
    QGLViewer::init();

    GLfloat globalLightDirection[] = { 100.0, 120.0, -110.0, 1.0 };
    GLfloat globalLightIntensity[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat ambientIntensity[] = { 0.3, 0.3, 0.3, 100.0 };

    glClearColor(0.1, 0.1, 0.1, 0.0);   // Set window color to dark.

    glEnable(GL_DEPTH_TEST);            // Draw only closest surfaces

    glEnable(GL_LIGHTING);              // Set up ambient light.
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientIntensity);

    glEnable(GL_LIGHT0);                // Set up sunlight.
    glLightfv(GL_LIGHT0, GL_POSITION, globalLightDirection);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, globalLightIntensity);

    glEnable(GL_COLOR_MATERIAL);        // Configure glColor().
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    setRadiusAndCenter();
}

void SolarSystem::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear window.
    glShadeModel(GL_SMOOTH);
    _sun->draw();
}

void SolarSystem::setRadiusAndCenter() {
    const float3 min(-100, -100, -100);
    const float3 max(100, 100, 100);
    setSceneBoundingBox(qglviewer::Vec(min.x, min.y, min.z), qglviewer::Vec(max.x, max.y, max.z));

    qglviewer::Quaternion q;
    q.setAxisAngle(qglviewer::Vec(4, 2, 3), 1.f);
    camera()->setOrientation(q);
    showEntireScene();
}
