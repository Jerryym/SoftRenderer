#include "Application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationClass())
{
    ui->setupUi(this);
    this->resize(1280, 768);
    canvas = new QImage();

    loop = new RenderLoop(width(), height(), nullptr);
    loopThread = new QThread(this);

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Application::fpsTimeOut);

    //render thread
    loop->moveToThread(loopThread);
    connect(loopThread, &QThread::finished, loop, &RenderLoop::deleteLater);
    connect(loopThread, &QThread::started, loop, &RenderLoop::loop);
    connect(loop, &RenderLoop::frameOut, this, &Application::receiveFrame);

    //begin the thread
    loopThread->start();
    timer->start(1000);
}

Application::~Application()
{
    delete ui;

    loop->stopIt();
    loopThread->quit();
    loopThread->wait();

    if (canvas)      delete canvas;
    if (loopThread)     delete loopThread;

    loop = nullptr;
    canvas = nullptr;
    loopThread = nullptr;
}

void Application::receiveFrame(unsigned char* data)
{
    if (canvas) delete canvas;
    canvas = new QImage(data, width(), height(), QImage::Format_RGBA8888);
    update();
}

void Application::paintEvent(QPaintEvent* event)
{
    if (canvas)
    {
        QPainter painter(this);
        painter.drawImage(0, 0, *canvas);
    }
    QWidget::paintEvent(event);
}

void Application::fpsTimeOut()
{
    int fps = loop->getFps();
    loop->setFpsZero();
    std::cout << "Fps: " << fps << std::endl;
}