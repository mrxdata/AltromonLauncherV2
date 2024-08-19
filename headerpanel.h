#ifndef HEADERPANEL_H
#define HEADERPANEL_H

#include <QWidget>
#include <QLabel>

class HeaderPanel : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderPanel(QWidget *parent = nullptr);
    ~HeaderPanel();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *iconLabel;
    QLabel *logoLabel;
};

#endif // HEADERPANEL_H
