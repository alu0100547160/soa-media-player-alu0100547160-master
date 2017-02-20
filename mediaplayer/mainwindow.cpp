#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   //  CODIGO CAMARA ---------------
   camera = new QCamera(this);
   viewfinder = new QVideoWidget(this);

   // CODIGO VIDEO -----------------
   reproductor = new QMediaPlayer(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCamara_triggered()
{
    camera->setViewfinder(viewfinder); // (ui->widget)
    viewfinder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    setCentralWidget(viewfinder);
    camera->start();
}

void MainWindow::on_actionApagar_triggered()
{
    camera->stop();
}

void MainWindow::on_actionAbrirVideo_triggered()
{
    if (camera->status() == QCamera::ActiveState)
        camera->stop();

    reproductor->setVideoOutput(viewfinder);
    setCentralWidget(viewfinder);

    QString Video = QFileDialog::getOpenFileName(this,"Abrir Video","","video file (*.*)");
    on_actionStopVideo_triggered();//Parar el video que se este reproduciendo cuando quiero bsucar otro

    reproductor->setMedia(QUrl::fromLocalFile(Video));
    on_actionPlayVideo_triggered();//Reproducir apenas abro el archivo

}

void MainWindow::on_actionPlayVideo_triggered()
{
    reproductor->play();
}

void MainWindow::on_actionPauseVideo_triggered()
{
    reproductor->pause();
}

void MainWindow::on_actionStopVideo_triggered()
{
    reproductor->stop();
}

void MainWindow::on_actionRewindVideo_triggered()
{
    reproductor->setPlaybackRate(0);
}

void MainWindow::on_actionForwardVideo_triggered()
{
   // reproductor->setPla
}
