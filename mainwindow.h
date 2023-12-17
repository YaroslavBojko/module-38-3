#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaContent>

#include <QFileDialog>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filePath;
    QImage blurImage(QImage imageSource, int blurValue);
    void openNewImage(QString sourceImage, int  newValue);

public slots:
    void openFile();
    void blurImage();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
