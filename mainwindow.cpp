#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::blurImage(QImage imageSource, int blurValue)
{
    if(imageSource.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(imageSource));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurValue);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result (imageSource.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0, 0, imageSource.width(), imageSource.height()));
    return result;
}

void MainWindow::openNewImage(QString sourceImage, int newValue)
{
    ui->label->setPixmap(QPixmap::fromImage(blurImage(QImage(sourceImage), newValue).scaled(
                                                ui->label->width(),
                                                ui->label->height(),Qt::KeepAspectRatio)));
}


void MainWindow::openFile()
{
    filePath = QFileDialog::getOpenFileName(nullptr,
                                            "Open image jpg",
                                            "/module-38-3/",
                                            "image files (*.jpg)"
                                            );
    openNewImage(filePath, ui->horizontalSlider->value());
}

void MainWindow::blurImage()
{
    openNewImage(filePath, ui->horizontalSlider->value());
}
