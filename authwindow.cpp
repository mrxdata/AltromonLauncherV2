#include "authwindow.h"
#include "ui_authwindow.h"
#include <QDebug>
#include <QMessageBox>

AuthWindow::AuthWindow(QWidget *parent)
    : BaseWindow(parent), ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    connect(ui->authButton, &QPushButton::clicked, this, &AuthWindow::on_authButton_clicked);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}


void AuthWindow::on_authButton_clicked()
{
    emit authSuccessful();
}

