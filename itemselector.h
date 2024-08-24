// itemselector.h
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
    void initializeItems();
    void updateLayout();

    QPushButton *selectedItem;
    QVBoxLayout *mainLayout;
    QHBoxLayout *itemsLayout;
    QVector<QPushButton*> items;
    QVector<QLabel*> labels;
    int itemCount;
};

#endif // ITEMSELECTOR_H
