#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "in_out.h"
#include "model.h"

#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup the UI object
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    // Delete the UI object
    delete ui;
}

/**
 * \brief Load figure from file
 * 
 **/
void MainWindow::on_LoadFigureButton_clicked()
{
    // Open dialog to select file to load
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Открытие файла",
        "",
        "Текстовый файл с моделью вида OBJ (*.txt)");

    // If no file was selected, return
    if (filename.isEmpty())
        return;

    // Load model from file
    static model_t* model = LoadModel(filename.toStdString().c_str());

    // If model was not loaded, show error message
    if (!model)
    {
        QMessageBox::information(
			this,
			"Ошибка",
			"Не удалось загрузить модель из файла");
        return;
    }


}