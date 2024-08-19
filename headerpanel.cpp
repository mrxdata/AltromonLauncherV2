#include "headerpanel.h"
#include <QPainter>
#include <QLinearGradient>
#include <QGraphicsBlurEffect>
#include <qapplication.h>

HeaderPanel::HeaderPanel(QWidget *parent)
    : QWidget(parent),
    iconLabel(new QLabel(this)),
    logoLabel(new QLabel(this)),
    closeButton(new QPushButton(this)),
    collapseButton(new QPushButton(this))
{
    setFixedHeight(36);
    setFixedWidth(960);
    setAutoFillBackground(true);

    //LogoIcon
    QPixmap iconPixmap(":/resources/img/altromon-64x-v2.png");
        if(!iconPixmap.isNull()) {
    iconLabel->setPixmap(iconPixmap);
    iconLabel->setFixedSize(24, 24);
    iconLabel->setScaledContents(true);
    iconLabel->move(10, (height() - iconLabel->height()) / 2);
    }

    //LogoText
    QPixmap logoPixmap(":/resources/img/altromonfontglow.png");
    if(!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap);
        logoLabel->setFixedSize(logoPixmap.size()/5.5);
        logoLabel->setScaledContents(true);
        logoLabel->move(iconLabel->x() + iconLabel->width() + 2, (height() - logoLabel->height()) / 2);
    }

    int buttonSpacing = 31;

    QPixmap collapsePixmap(":/resources/img/CollapseBtn.png");
    collapseButton->setIcon(QIcon(collapsePixmap));
    collapseButton->setIconSize(QSize(30, 30));
    collapseButton->setFlat(true);
    collapseButton->setFixedSize(30, 30);
    collapseButton->setStyleSheet(
        "QPushButton {"
        "border: none;"
        "margin-top: 13px"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/resources/img/CollapseBtn.png);"
        "margin-top: 13px"
        "}");
    collapseButton->move(width() - collapseButton->width() - buttonSpacing, (height() - collapseButton->height()) / 2);


    QPixmap closePixmap(":/resources/img/CloseBtn.png");
    closeButton->setIcon(QIcon(closePixmap));
    closeButton->setIconSize(QSize(30, 30));
    closeButton->setFlat(true);
    closeButton->setFixedSize(30, 30);
    closeButton->setStyleSheet(
        "QPushButton {"
        "border: none;"
        "background: transparent;"
        "}"
        "QPushButton:hover {"
        "background: transparent;"
        "border-image: url(:/resources/img/CloseBtn.png);"
        "}");
    closeButton->move(width() - closeButton->width() - 3, (height() - closeButton->height()) / 2);

    connect(closeButton, &QPushButton::clicked, this, &HeaderPanel::closeButtonClicked);
    connect(collapseButton, &QPushButton::clicked, this, &HeaderPanel::collapseButtonClicked);
}

HeaderPanel::~HeaderPanel()
{
}

void HeaderPanel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    //Background
    painter.setBrush(QColor(24, 24, 24)); // #181818
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    //GlowLine
    QLinearGradient gradient(0, height() - 2, width(), height() - 2);
    gradient.setColorAt(0, QColor(110, 100, 200)); // #6c62c7
    gradient.setColorAt(1, QColor(210, 120, 144)); // #bf6590

    QRect gradientRect(0, height() - 2, width(), 2);
    painter.fillRect(gradientRect, gradient);

}

void HeaderPanel::closeButtonClicked()
{
    QApplication::quit();
}

void HeaderPanel::collapseButtonClicked()
{
    if (QWidget *window = this->window()) {
        window->showMinimized();
    }
}
