#pragma once

#include <QtWidgets/QMainWindow>
#include <QImage>
#include <QPainter>
#include <QThread>
#include <QTimer>
#include "ui_Application.h"
#include "RenderLoop.h"

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationClass; };
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

    void fpsTimeOut();

private:
    void receiveFrame(unsigned char* data);
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::ApplicationClass *ui;
    QImage* canvas;
    QTimer* timer;
    QThread* loopThread;
    RenderLoop* loop;
};
