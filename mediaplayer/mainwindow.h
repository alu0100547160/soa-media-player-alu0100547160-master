#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtMultimedia>
//#include <QtMultimediaWidgets>
#include <QMediaPlayer>
#include "QVideoWidget"
#include "QFileDialog" // gestor de archivos del ssoo
#include "QProgressBar" // barra de porcentaje
#include "QSlider" // barra de carga
#include "QCamera"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); // Stop

    void on_actionCamara_triggered();

    void on_actionApagar_triggered();

    void on_actionAbrirVideo_triggered();

    void on_actionPlayVideo_triggered();

    void on_actionPauseVideo_triggered();

    void on_actionStopVideo_triggered();

    void on_actionRewindVideo_triggered();

    void on_actionForwardVideo_triggered();

private:
    Ui::MainWindow *ui;
    QCamera* camera;
    QVideoWidget* viewfinder;
    QMediaPlayer* reproductor;
};

#endif // MAINWINDOW_H
