#ifndef HEADERPANEL_H
#define HEADERPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class HeaderPanel : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderPanel(QWidget *parent = nullptr);
    ~HeaderPanel();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void closeButtonClicked();
    void collapseButtonClicked();

private:
    QLabel *iconLabel;
    QLabel *logoLabel;
    QPushButton *closeButton;
    QPushButton *collapseButton;

    void setupButtons();
};

#endif // HEADERPANEL_H
