#include "Nav.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nav w;
    w.show();
    return a.exec();
}
