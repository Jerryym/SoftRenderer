#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include "ui_Dialog_Application.h"

class Dialog_Application : public QMainWindow
{
    Q_OBJECT

public:
    Dialog_Application(QWidget *parent = nullptr);
    ~Dialog_Application();

protected:
    void paintEvent(QPaintEvent* event) override;
    void receiveFrame(unsigned char* image);

private:
    Ui::Dialog_ApplicationClass ui;
    QImage* canvas;                     //ªÊ÷∆∂‘œÛ
};
