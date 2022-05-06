#include "pixelperfect.h"

PixelPerfect::PixelPerfect(QWidget *parent)
    : QWidget(parent)
{
    resize(1920,1000);
    mainLayout = new QGridLayout(this);
    label = new QTextEdit(this);

    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo &cameraInfo : cameras) {

            camera = new QCamera(cameraInfo);
    }
    //QImage image("/home/deymos/MY_PROJECTS/build-PixelPerfect-Desktop_Qt_5_15_2_GCC_64bit-Debug/ing.png");

    viewFinder = new QCameraViewfinder();
    viewFinder->show();
    camera->setViewfinder(viewFinder);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QCameraViewfinderSettings viewFinderSettings;
    probe = new QVideoProbe();
    connect(probe, &QVideoProbe::videoFrameProbed, this, &PixelPerfect::processFrame);
    probe->setSource(camera);
    camera->start();
    viewFinderSettings.setResolution(320,240);
    camera->setViewfinderSettings(viewFinderSettings);
    mainLayout->addWidget(label,0,0,1,1);
   //mainLayout->addWidget(viewFinder,1,0,1,1);

}

PixelPerfect::~PixelPerfect()
{
}

void PixelPerfect::processFrame(QVideoFrame frame)
{
    QVideoFrame cloneFrame(frame);
    cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
    QImage image = cloneFrame.image();
    QColor color;
    QString mas = "  abc0123456789$w#@N";
    QString img;
    int avg1;
    int avg2;
    int avg3;
    int avg4;
    int avgfin;
    QFont font;
    font.setPixelSize(10);
    label->setFont(font);
    for(int i = 0; i<240; i+=2) {
        for(int j=0; j<240; j+=2) {
           color = image.pixel(j,i);

           avg1 = (color.red()+ color.green() + color.blue())/3;
           color = image.pixel(j+1,i);
           avg2 = (color.red()+ color.green() + color.blue())/3;
           image.pixel(j,i+1);
           avg3 = (color.red()+ color.green() + color.blue())/3;
           image.pixel(j+1,i+1);
           avg4 = (color.red()+ color.green() + color.blue())/3;
           avgfin = (avg1+avg2+avg3+avg4)/4;
           img.append(mas.at(avgfin/15));
           img.append(".");
        }
        img.append("\n");
    }
    label->setText(img);

}

