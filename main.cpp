#include <QtGui/QApplication>
#include "ambient_light_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Ambient_Light_Window *ambient = new Ambient_Light_Window;
    ambient->show();
    return app.exec();
}
