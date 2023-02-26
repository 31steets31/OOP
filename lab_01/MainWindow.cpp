#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "in_out.h"
#include "model.h"
#include "errors.h"
#include "task_manager.h"
#include "tools.h"

#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

/**
 * \brief Constructor
 * 
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup the UI object
    ui->setupUi(this);
}

/**
 * \brief Destructor
 *
 */
MainWindow::~MainWindow(void)
{
    // Free the model
    options_t opt = { DESTROY_MODEL, { NULL } };

    int rc = Process(opt);

    // Delete the UI object
    delete ui;

}

/**
 * \brief Load figure from file
 * 
 */
void MainWindow::on_LoadFigureButton_clicked(void)
{
    // Open dialog to select file to load
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Open file",
        "",
        "Text files with OBJ form data (*.txt)"
    );

    // If no file was selected, return
    if (filename.isEmpty())
        return;

    // Create options object
    options_t opt = { LOAD_MODEL, { ConvertQString(filename) } };

    // Load model from file
    errors rc = Process(opt);

    // If model was not loaded, show error message
    if (rc != ERR_SUCCESS)
        PrintErrorMessage(rc);
}