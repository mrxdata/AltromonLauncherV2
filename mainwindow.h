#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basewindow.h"
#include <QMainWindow>

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
