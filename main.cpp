#include "authwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <qstackedwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AltromonLauncher_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QStackedWidget stackedWidget;

    AuthWindow authWindow;
    MainWindow mainWindow;

    stackedWidget.setWindowFlags(Qt::FramelessWindowHint);
    stackedWidget.setWindowIcon(QIcon(":/resources/img/altromon-v2-64x.ico"));

    stackedWidget.addWidget(&authWindow);
    stackedWidget.addWidget(&mainWindow);

    stackedWidget.setCurrentWidget(&authWindow);

    QObject::connect(&authWindow, &AuthWindow::authSuccessful, &a, [&]() {
        stackedWidget.setCurrentWidget(&mainWindow);
    });

    stackedWidget.show();

    return a.exec();
}
