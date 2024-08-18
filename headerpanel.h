#ifndef HEADERPANEL_H
#define HEADERPANEL_H

#include <QWidget>

class HeaderPanel : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderPanel(QWidget *parent = nullptr);
    ~HeaderPanel();

protected:
    void paintEvent(QPaintEvent *event) override;

private:

};

#endif // HEADERPANEL_H
