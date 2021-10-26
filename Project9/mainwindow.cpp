#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slider->setMaximum(200);
    ui->slider->setMinimum(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

    int size = ui->slider->value();
    if(ui->red->isChecked())
    {
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(100, 50, size, size);
    } else if(ui->blue->isChecked()){
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.drawEllipse(100, 50, size, size);
    } else if(ui->yellow->isChecked()){
        painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        painter.drawEllipse(100, 50, size, size);
    } else {
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        painter.drawEllipse(100, 50, size, size);
    }
    if(ui->rect->isChecked())
    {
        painter.drawRect(100, 50, size, size);
    }
}

void MainWindow::on_red_clicked()
{
    repaint();
}

void MainWindow::on_blue_clicked()
{
    repaint();
}

void MainWindow::on_yellow_clicked()
{
    repaint();
}

void MainWindow::on_slider_actionTriggered()
{
    repaint();
}

void MainWindow::on_rect_clicked()
{
    repaint();
}

