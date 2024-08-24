#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "basewindow.h"
#include <QtNetwork/qnetworkreply.h>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

signals:
    void authSuccessful();

private slots:
    void on_authButton_clicked();
    void onLoginFinished();
    void onSavePassStateChanged(int state);
    void forgotPasswordClicked();
    void registerClicked();

private:
    Ui::AuthWindow *ui;
    QNetworkAccessManager *networkManager;
};

#endif // AUTHWINDOW_H
