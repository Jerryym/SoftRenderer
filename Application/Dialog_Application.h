#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Dialog_Application.h"

class Dialog_Application : public QMainWindow
{
    Q_OBJECT

public:
    Dialog_Application(QWidget *parent = nullptr);
    ~Dialog_Application();

private:
    Ui::Dialog_ApplicationClass ui;
};
