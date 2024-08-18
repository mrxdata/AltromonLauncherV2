// authwindow.h
#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "basewindow.h"
#include <QDialog>

class AuthWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();
};

#endif // AUTHWINDOW_H
