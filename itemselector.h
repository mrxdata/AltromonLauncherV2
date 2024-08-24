#ifndef ITEMSELECTOR_H
#define ITEMSELECTOR_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class ItemSelector : public QWidget {
    Q_OBJECT

public:
    explicit ItemSelector(QWidget *parent = nullptr);

private slots:
    void selectItem();

private:
    QPushButton *selectedItem;
    QVBoxLayout *mainLayout;
    QHBoxLayout *itemsLayout;
    QVector<QPushButton*> items;
    QVector<QLabel*> labels;
    QVector<QVBoxLayout*> itemLayouts; // Хранит макеты для кнопок и меток
    int itemCount;
};

#endif // ITEMSELECTOR_H
