#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <QTimer>
#include <QWidget>

class TimeCounter : public QObject {
    Q_OBJECT
public:
    TimeCounter(QWidget *parent);
    ~TimeCounter();

    int now() const { return _counter; }

private slots:
    void tick();

private:
    QWidget *_parent;

    QTimer *_timer;
    int _counter;
};

#endif // TIMECOUNTER_H
