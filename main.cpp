#include "authwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>

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
    AuthWindow authWindow;
    MainWindow mainWindow;

    QObject::connect(&authWindow, &AuthWindow::authSuccessful, &a, [&]() {
        mainWindow.show();
        authWindow.close();
    });

    authWindow.show();

    return a.exec();
}
