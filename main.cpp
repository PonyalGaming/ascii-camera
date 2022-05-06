#include "pixelperfect.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPerfect w;
    w.show();
    return a.exec();
}
