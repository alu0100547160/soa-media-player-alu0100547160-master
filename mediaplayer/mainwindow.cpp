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
  // viewfinder = new QVideoWidget(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCamara_triggered()
{
     // (ui->widget)
   // viewfinder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    //setCentralWidget(viewfinder);
    camera->setViewfinder(ui->viewfinder);
    camera->setCaptureMode(QCamera::CaptureViewfinder);

    if(reproductor->state() == QMediaPlayer::StoppedState)
         camera->start();
    else
         reproductor->stop();
         camera->start();
}

void MainWindow::on_actionApagar_triggered()
{
    camera->stop();
}

void MainWindow::on_actionAbrirVideo_triggered()
{
    if (camera->state() == QCamera::ActiveState)
        camera->stop();

    reproductor->setVideoOutput(ui->viewfinder);
    QString Video = QFileDialog::getOpenFileName(this,"Abrir Video","","video file (*.*)");
    on_actionStopVideo_triggered();//Parar el video que se este reproduciendo cuando quiero bsucar otro

    reproductor->setMedia(QUrl::fromLocalFile(Video));
    on_actionPlayVideo_triggered();//Reproducir apenas abro el archivo

}

void MainWindow::on_actionPlayVideo_triggered()
{
    reproductor->setPlaybackRate(0.99);
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
    reproductor->setPosition(reproductor->position()-2000);
    reproductor->play();

}

void MainWindow::on_actionForwardVideo_triggered()
{
    if(reproductor->state() == QMediaPlayer::PlayingState){
       reproductor->setPlaybackRate(1.5);
    }

}


void MainWindow::on_Stop_clicked()
{
   //Stop, para detener la reproducción del archivo o la captura de la webcam.
    camera->stop();
    reproductor->stop();
}


void MainWindow::on_Play_clicked()
{
//Play / Pause, para iniciar o pausar la reproducción de una película.
//   Si no se está reproduciendo nada o se está viendo la webcam, al pulsar este control se deberá abrir un cuadro de diálogo para seleccionar el archivo de vídeo y después comenzar la reproducción.
 //   Si se estaba reproduciendo un archivo, esta se pondrá en pausa.

    if(reproductor->state() == QMediaPlayer::StoppedState){
        on_actionAbrirVideo_triggered();
    //    on_actionPlayVideo_triggered();
     }
    else if(reproductor->state() == QMediaPlayer::PausedState){
        on_actionPlayVideo_triggered();
    }else
        on_actionPauseVideo_triggered();
}
