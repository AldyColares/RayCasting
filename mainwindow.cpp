#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(mainSlot()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainSlot()
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

    Pixel pixel;
    GridPixel* gridPixel = new GridPixel();


    ColorPixels colorCount;

    Scenario *scenario = new Scenario();
    scenario->LoadScenario();

    ScenarioObject* scenarioObjectTransformCoordCamera;
    CoordinateTransformation *coordinateTransformation = new CoordinateTransformation();

    //the vectices of the material are oriented in camera coordinates.
    scenarioObjectTransformCoordCamera = coordinateTransformation->coordinateTransformationbyWorldForCamera
            (scenario->getMaterial(), scenario->getCamera());

    int sizeX = 500;
    int sizeY = 500;
    gridPixel = colorCount.caluletionColorPixels(sizeX, sizeY, scenario);

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            pixel = gridPixel->getColorPixel(x,y);
            image.setPixel(x, y, qRgb(pixel.red, pixel.green ,pixel.blue));
        }
    }
    std::cout << "=========terminou========" << endl;
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap( QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);

}
