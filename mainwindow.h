#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loadmaterial.h"
#include "camera.h"
#include "coordinatetransformation.h"
#include "light.h"
#include "colorpixels.h"
#include "scenario.h"
#include "scenarioObject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void mainSlot();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
