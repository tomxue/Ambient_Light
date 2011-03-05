/* 
 * Copyright (C) 2010 Tom Xue <TomXue0126@gmail.com>
 *
 * To show the ambient light brightness, on N900 
 *
 */

#include "ambient_light_window.h"
#include "ui_ambient_light_window.h"
#include <QFile>
#include <QIODevice>
#include <QByteArray>
#include <QTimer>
#include <QTextStream>
#include <QStringList>

//Thread part...
myThread::myThread(QObject *parent)
    : QThread(parent)
{
}

void myThread::run()
{
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateData()));
    timer.start(20); // 50 Hz update rate
    exec();
}

void myThread::updateData()
{
     QFile file("/sys/class/i2c-adapter/i2c-2/2-0029/adc0");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
     QTextStream in(&file);
     QString data = in.readAll();
     processData(data);
}

void myThread::processData(QString &data)
{
    QStringList data_splited = data.split(" ");

    x = data_splited[0];

    emit deviceAmbient(x);
}
//Thread part...



Ambient_Light_Window::Ambient_Light_Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    lineEdit->setText("NaN");
    onethread = new myThread(this);
    connect(onethread, SIGNAL(deviceAmbient(QString)),
            this, SLOT(showData(QString)));
    onethread->start(QThread::NormalPriority);
}

void Ambient_Light_Window::showData(QString x)
{
    lineEdit->setText(x);
}

