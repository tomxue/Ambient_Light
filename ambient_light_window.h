#ifndef AMBIENT_LIGHT_WINDOW_H
#define AMBIENT_LIGHT_WINDOW_H

#include <QMainWindow>
#include "ui_ambient_light_window.h"
#include <QThread>
#include <QString>

class myThread : public QThread
{
  Q_OBJECT

public:
    myThread(QObject *parent = 0);
    void run();
    QString x;

public slots:
    void updateData();
    void processData(QString &data);

signals:
    void deviceAmbient(QString x);

};

class Ambient_Light_Window : public QMainWindow, public Ui::Ambient_Light_Window
{
    Q_OBJECT

public:
    Ambient_Light_Window(QWidget *parent = 0);

public slots:
    void showData(QString x);

private:
    myThread *onethread;
};

#endif // AMBIENT_LIGHT_WINDOW_H
