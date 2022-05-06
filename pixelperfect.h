#ifndef PIXELPERFECT_H
#define PIXELPERFECT_H

#include <QWidget>
#include <QCamera>
#include <QTextEdit>
#include <QGridLayout>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QVideoProbe>
#include <QColor>
#include <QCameraViewfinderSettings>

class PixelPerfect : public QWidget
{
    Q_OBJECT

public:
    PixelPerfect(QWidget *parent = nullptr);
    QGridLayout * mainLayout;
    QCamera * camera;
    QTextEdit * label;
    QCameraViewfinder * viewFinder;
    QVideoProbe * probe;
    ~PixelPerfect();
private slots:
    void processFrame(QVideoFrame frame);
};
#endif // PIXELPERFECT_H
