#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "in_out.h"
#include "model.h"
#include "errors.h"
#include "process.h"
#include "paint.h"

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

    // Create new canvas
    QGraphicsScene *canvas = new QGraphicsScene(this);

    ui->graphicsView->setScene(canvas);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    canvas->setSceneRect(0, 0, 1, 1);
}

/**
 * \brief Destructor
 *
 */
MainWindow::~MainWindow(void)
{
    // Free the model
    options_t opt;
    opt.action = DESTROY_MODEL;

    int rc = Process(opt);

    // Delete the UI object
    delete ui;

}

/**
 * \brief Draw model
 * 
 * \return 
 **/
errors MainWindow::DrawModel(void)
{
    // Create canvas
    canvas_t canvas;

    canvas.canvas = ui->graphicsView->scene();

    // Set options
    options_t opt;

    opt.action = DRAW_MODEL;
    opt.params.canvas = canvas;

    // Draw model
    return Process(opt);
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
    options_t opt;
    opt.action = LOAD_MODEL;
    strcpy(opt.params.filename, filename.toStdString().c_str());

    // Load model from file
    errors rc = Process(opt);

    // If model was not loaded, show error message
    if (rc != ERR_SUCCESS)
    {
        PrintErrorMessage(rc);
        return;
    }

    // Draw model
    rc = DrawModel();

    // If model was not drawn, show error message
    if (rc != ERR_SUCCESS)
		PrintErrorMessage(rc);
}