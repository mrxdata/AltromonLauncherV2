#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basewindow.h"
#include "itemselector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ItemSelector *itemSelector;
};

#endif // MAINWINDOW_H
