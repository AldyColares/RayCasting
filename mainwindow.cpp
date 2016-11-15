#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
/*
    light light0;

    light0.red = 0.5;
    light0.green = 0.5;
    light0.blue = 0.5;
    light0.x = 0.0;
    light0.y = 5.0;
    light0.z = -2.0;
*/
    // load Nth material for scenario.
    LoadMaterial loca;
    ScenarioObject scenarioObject = loca.loadObject();

    // Load coordinates of the Camera; We can have more than one.
    Camera camera;
    camera.loadCamera();

    Scenario scenario(scenarioObject);

    CoordinateTransformation coordinateTransformation;
    // the vectices of the material are oriented in camera coordinates.
    scenarioObject = coordinateTransformation.coordinateTransformationbyWorldForCamera
                                             (scenarioObject, camera);

    ui->setupUi(this);

    int sizeX = 500;
    int sizeY = 500;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

    ColorPixels colorCount;
    colorCount.caluletionColorPixels(sizeX, sizeY, scenario);

    for (int l = 0; l < sizeX; l++)
    {
        for (int c = 0; c < sizeY; c++)
        {
            image.setPixel(l, c, qRgb(0,0,0));


        }
    }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap( QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);

}

MainWindow::~MainWindow()
{
    delete ui;
}
