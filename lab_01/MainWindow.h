#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <QMainWindow>

#include "ui_MainWindow.h"
#include "errors.h"

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
    errors DrawModel(void);
    void on_LoadFigureButton_clicked(void);
    void on_TransferButton_clicked(void);
    void on_ScaleButton_clicked(void);
    void on_RotateButton_clicked(void);
    void on_ClearGraph_clicked(void);

private:
    Ui::MainWindow *ui;
};

#endif // __MAINWINDOW__