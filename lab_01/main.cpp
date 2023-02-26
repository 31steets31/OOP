#include "MainWindow.h"
#include <QApplication>

/**
 * \brief Main function
 * 
 * \param argc
 * \param argv
 * \return 
 **/
int main(int argc, char *argv[])
{
    // Create a QApplication object
    QApplication a(argc, argv);

    // Create a MainWindow object
    MainWindow w;

    // Show the window
    w.show();

    // Start the event loop
    return a.exec();
}
