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

/**
 * \brief Transfer model by offset
 * 
 */
void MainWindow::on_TransferButton_clicked(void)
{
    // Get transfer offset (string)
    QString s_dx = ui->OffsetXField->toPlainText();
    QString s_dy = ui->OffsetYField->toPlainText();
    QString s_dz = ui->OffsetZField->toPlainText();

    // Check if coordinates are valid
    bool check_dx, check_dy, check_dz;

    double dx = s_dx.toDouble(&check_dx);
    double dy = s_dy.toDouble(&check_dy);
    double dz = s_dz.toDouble(&check_dz);

    if (!check_dx && !check_dy && !check_dz)
    {
        errors err = ERR_INCORRECT_OFFSET;

        PrintErrorMessage(err);
		return;
	}

    // Create options object
    options_t opt;
    opt.action = TRANSFER_MODEL;
    opt.params.t_coord = { 
        (check_dx) ? dx : 0, 
        (check_dy) ? dy : 0,
        (check_dz) ? dz : 0
    };

    // Transfer model
    errors rc = Process(opt);

    // If model was not transferred, show error message
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

/**
 * \brief Rotate model by angle
 * 
 */
void MainWindow::on_RotateButton_clicked(void)
{
    // Get center of rotation (string)
    QString s_x = ui->CenterXField->toPlainText();
    QString s_y = ui->CenterYField->toPlainText();
    QString s_z = ui->CenterZField->toPlainText();

    // Check if coordinates are valid
    bool check_x, check_y, check_z;

    double x = s_x.toDouble(&check_x);
    double y = s_y.toDouble(&check_y);
    double z = s_z.toDouble(&check_z);

    if (!check_x || !check_y || !check_z)
    {
		errors err = ERR_INCORRECT_CENTER;

		PrintErrorMessage(err);
		return;
	}

	// Get rotation angles (string)
	QString s_angle_x = ui->AngleXField->toPlainText();
    QString s_angle_y = ui->AngleYField->toPlainText();
    QString s_angle_z = ui->AngleZField->toPlainText();

    // Check if angles are valid
    bool check_angle_x, check_angle_y, check_angle_z;

    double angle_x = s_angle_x.toDouble(&check_angle_x);
    double angle_y = s_angle_y.toDouble(&check_angle_y);
    double angle_z = s_angle_z.toDouble(&check_angle_z);

    if (!check_angle_x && !check_angle_y && !check_angle_z)
    {
		errors err = ERR_INCORRECT_ANGLES;

		PrintErrorMessage(err);
		return;
	}

	// Set options
	options_t opt;

	opt.action = ROTATE_MODEL;
    opt.params.r_angles = {
        x,
        y,
        z,
		(check_angle_x) ? angle_x : 0,
		(check_angle_y) ? angle_y : 0,
		(check_angle_z) ? angle_z : 0
	};

	// Rotate model
	errors rc = Process(opt);

	// If model was not rotated, show error message
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

/**
 * \brief Clear graph
 *
 */
void MainWindow::on_ClearGraph_clicked(void)
{
    // Clear canvas
	canvas_t canvas;

	canvas.canvas = ui->graphicsView->scene();

	ClearCanvas(canvas);
}
