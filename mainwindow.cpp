#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   /*
    ui->setupUi(this);
    int sizeX = 500;
    int sizeY = 500;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

    for (int l = 0; l < sizeX; l++)
    {
        for (int c = 0; c < sizeY; c++)
        {
            image.setPixel(l, c, qRgb(255,0,0));

        }
    }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap( QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
