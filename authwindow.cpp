#include "authwindow.h"
#include "ui_authwindow.h"
#include <QBoxLayout>
#include <QDesktopServices>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
#include <QGraphicsBlurEffect>


AuthWindow::AuthWindow(QWidget *parent)
    : BaseWindow(parent),
    ui(new Ui::AuthWindow),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    QWidget *backgroundWidget = new QWidget(this);
    backgroundWidget->setStyleSheet(
        "background-color: rgba(0, 0, 0, 0.15);"
        "border-radius: 20px;"
        );

    int bgWidth = 360;
    int bgHeight = 360;
    int posX = (width() - bgWidth) / 2;
    int posY = (height() - bgHeight) / 2;

    backgroundWidget->setGeometry(posX, posY, bgWidth, bgHeight);
    backgroundWidget->lower();

    QPushButton *registerButton = new QPushButton(this);
    registerButton->setText("Зарегистрироваться");
    registerButton->setCursor(Qt::PointingHandCursor);
    registerButton->setStyleSheet(
        "QPushButton {"
        "background-color: transparent;"
        "color: #FFFFFF;"
        "border: none;"
        "font-size: 14px;"
        "font-weight: bold;"
        "text-align: center;"
        "}"
        "QPushButton:hover {"
        "color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 #7067d2, stop:1 #c86997);"
        "}"
        );

    QPushButton *forgotPasswordButton = new QPushButton(this);
    forgotPasswordButton->setText("Сменить пароль");
    forgotPasswordButton->setCursor(Qt::PointingHandCursor);
    forgotPasswordButton->setStyleSheet(
        "QPushButton {"
        "background-color: transparent;"
        "margin-top: 15px;"
        "color: #FFFFFF;"
        "border: none;"
        "font-size: 14px;"
        "font-weight: bold;"
        "text-align: center;"
        "}"
        "QPushButton:hover {"
        "color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 #7067d2, stop:1 #c86997);"
        "}"
        );

    ui->authButton->setStyleSheet(
        "QPushButton {"
        "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.2, y2:0, stop:0 #e2699a, stop:1 #7467d6);"
        "color: #FFFFFF;"
        "border: none;"
        "border-radius: 10px;"
        "padding: 10px 20px;"
        "font-size: 16px;"
        "font-weight: bold;"
        "text-align: center;"
        "}"
        "QPushButton:hover {"
        "background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 #7067d2, stop:1 #c86997);"
        "}"
        "QPushButton:pressed {"
        "background-color: #4A00E0;"
        "}"
        );

    ui->SavePass->setStyleSheet(
        "QCheckBox {"
        "color: #E6E6E6;"
        "font-size: 16px;"
        "}"

        "QCheckBox::indicator {"
        "width: 24px;"
        "height: 24px;"
        "}"

        "QCheckBox::indicator:unchecked {"
        "background-color: rgba(255, 255, 255, 0.05);"
        "border-radius: 5px;"
        "}"

        "QCheckBox::indicator:checked {"
        "background-color: #8E2DE2;"
        "border-radius: 5px;"
        "image: url(:/resources/img/Checked.png);"
        "}"
        );


    ui->loginForm->setPlaceholderText("Логин");
    ui->loginForm->setStyleSheet("QLineEdit {"
                                 "background-color: rgba(255, 255, 255, 0.05);"
                                 "color: #E6E6E6;"
                                 "border-radius: 10px;"
                                 "padding: 10px;"
                                 "font-size: 16px;"
                                 "font-weight: bold;"
                                 "text-align: center;"
                                 "}");

    ui->passForm->setPlaceholderText("Пароль");
    ui->passForm->setStyleSheet("QLineEdit {"
                                 "background-color: rgba(255, 255, 255, 0.05);"
                                 "color: #E6E6E6;"
                                 "border-radius: 10px;"
                                 "padding: 10px;"
                                 "font-size: 16px;"
                                 "font-weight: bold;"
                                 "text-align: center;"
                                 "lineedit-password-character: 42;"
                                 "}");

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    blurEffect->setBlurRadius(0);
    ui->authButton->setGraphicsEffect(blurEffect);

    connect(ui->authButton,
            &QPushButton::clicked,
            this,
            &AuthWindow::on_authButton_clicked);

    connect(registerButton,
            &QPushButton::clicked,
            this,
            &AuthWindow::registerClicked);

    connect(forgotPasswordButton,
            &QPushButton::clicked,
            this,
            &AuthWindow::forgotPasswordClicked);
    connect(ui->SavePass,
            &QCheckBox::stateChanged,
            this,
            &AuthWindow::onSavePassStateChanged);


    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(container);

    layout->addWidget(registerButton);
    layout->addWidget(forgotPasswordButton);

    layout->setAlignment(registerButton, Qt::AlignHCenter);
    layout->setAlignment(forgotPasswordButton, Qt::AlignHCenter);

    container->setLayout(layout);
    container->setGeometry(posX, posY + 270, bgWidth, 80);

    ui->authText->move(posX + (bgWidth - ui->authText->width()) / 2, posY + 15);
    ui->loginForm->move(posX + (bgWidth - ui->loginForm->width()) / 2, posY + 70);
    ui->passForm->move(posX + (bgWidth - ui->passForm->width()) / 2, posY + 125);
    ui->SavePass->move(posX + (bgWidth - ui->SavePass->width()), posY + 170);
    ui->authButton->move(posX + (bgWidth - ui->authButton->width()) / 2, posY + 220);

    container->move(posX, posY + 270);

    QSettings settings("Altromon", "Launcher");
    if (settings.contains("username") && settings.contains("password")) {
        ui->loginForm->setText(settings.value("username").toString());
        ui->passForm->setText(settings.value("password").toString());
        ui->SavePass->setChecked(true);
    }
}

AuthWindow::~AuthWindow()
{
    delete ui;
}


void AuthWindow::on_authButton_clicked()
{
    QString username = ui->loginForm->text();
    QString password = ui->passForm->text();

    QUrl url("https://atromon.ob1lab.ru/api/auth/loginLauncher");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    qDebug() << "Request JSON: " << jsonData;

    QNetworkReply *reply = networkManager->post(request, jsonData);
    connect(reply, &QNetworkReply::finished, this, &AuthWindow::onLoginFinished);

    if (ui->SavePass->isChecked()) {
        QSettings settings("Altromon", "Launcher");
        settings.setValue("username", username);
        settings.setValue("password", password);
    }
}

void AuthWindow::onLoginFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response data: " << responseData;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();

        QString accessToken = jsonObj["accessToken"].toString();
        QString uuid = jsonObj["uuid"].toString();

        qDebug() << "Access Token: " << accessToken;
        qDebug() << "UUID: " << uuid;

        if (!accessToken.isEmpty() && !uuid.isEmpty()) {
            emit authSuccessful();
        } else {
            qDebug() << "Authorization failed: Missing access token or UUID";
        }
    } else {
        qDebug() << "Network error: " << reply->errorString();
    }
    reply->deleteLater();
}


void AuthWindow::onSavePassStateChanged(int state)
{
    QSettings settings("Altromon", "Launcher");
    if (state == Qt::Checked) {
        settings.setValue("username", ui->loginForm->text());
        settings.setValue("password", ui->passForm->text());
    } else {
        settings.remove("username");
        settings.remove("password");
    }
}

void AuthWindow::registerClicked()
{
    QDesktopServices::openUrl(QUrl("https://altromon.ob1lab.ru/register"));
}

void AuthWindow::forgotPasswordClicked()
{
    QDesktopServices::openUrl(QUrl("https://altromon.ob1lab.ru/profile"));
}
