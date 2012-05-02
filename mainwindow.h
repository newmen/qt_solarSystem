#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "solarsystem.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();
    
signals:
    
public slots:

private:
    SolarSystem *_solarSystem;
    
};

#endif // MAINWINDOW_H
