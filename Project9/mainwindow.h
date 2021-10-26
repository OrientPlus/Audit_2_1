#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <Qt>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_red_clicked();
    void on_blue_clicked();
    void on_yellow_clicked();
    void on_slider_actionTriggered();
    void on_rect_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
