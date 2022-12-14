#include "Dialog_Application.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog_Application w;
    w.show();
    return a.exec();
}
