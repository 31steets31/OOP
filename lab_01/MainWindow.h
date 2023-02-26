#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <QMainWindow>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoadFigureButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // __MAINWINDOW__