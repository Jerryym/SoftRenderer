#include "Dialog_Application.h"

Dialog_Application::Dialog_Application(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    canvas = new QImage();
}

Dialog_Application::~Dialog_Application()
{}

void Dialog_Application::paintEvent(QPaintEvent * event)
{
    if (canvas)
    {
        //¥¥Ω®± À¢painter
        QPainter painter(this);
        painter.drawImage(0, 0, *canvas);
    }
    QWidget::paintEvent(event);
}

void Dialog_Application::receiveFrame(unsigned char* image)
{
    if (canvas)      delete canvas;
    canvas = new QImage(image, width(), height(), QImage::Format_RGBA8888);
    update();
}
