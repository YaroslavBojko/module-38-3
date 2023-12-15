#include "mainwindow.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QMediaContent>

#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QFileDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWindow;
    QVBoxLayout vbox(&mainWindow);
    QLabel *label = new QLabel(&mainWindow);
    QSlider *slider = new QSlider(&mainWindow);
    slider->setOrientation(Qt::Horizontal);
    slider->setMaximum(0);
    slider->setMaximum(10);

    vbox.addWidget(label);
    vbox.addWidget(slider);

    auto *openFileButton = new QPushButton("Open", &mainWindow);
    vbox.addWidget(openFileButton);

    mainWindow.show();
    return a.exec();
}
