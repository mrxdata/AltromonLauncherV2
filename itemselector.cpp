// itemselector.cpp
#include "itemselector.h"
#include <QRandomGenerator>

ItemSelector::ItemSelector(QWidget *parent) : QWidget(parent), selectedItem(nullptr), itemCount(5) {
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 5, 5, 5); // Устанавливаем отступы для mainLayout

    itemsLayout = new QHBoxLayout();
    itemsLayout->setContentsMargins(5, 5, 5, 5); // Устанавливаем отступы для itemsLayout

    // Создаем остальные кнопки и заголовки
    for (int i = 0; i < itemCount; ++i) {
        QVBoxLayout *buttonLayout = new QVBoxLayout();
        QPushButton *item = new QPushButton(QString("Item %1").arg(i + 1), this);
        item->setFixedSize(76, 76);
        item->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                .arg(QRandomGenerator::global()->bounded(256))
                                .arg(QRandomGenerator::global()->bounded(256))
                                .arg(QRandomGenerator::global()->bounded(256)));
        connect(item, &QPushButton::clicked, this, &ItemSelector::selectItem);
        items.append(item);

        QLabel *label = new QLabel(QString("Label %1").arg(i + 1), this);
        labels.append(label);

        buttonLayout->addWidget(item);
        buttonLayout->addWidget(label);
        buttonLayout->setAlignment(Qt::AlignHCenter);
        itemsLayout->addLayout(buttonLayout);
    }

    mainLayout->addLayout(itemsLayout);
    setLayout(mainLayout);
}

void ItemSelector::selectItem() {
    QPushButton *clickedItem = qobject_cast<QPushButton*>(sender());
    if (clickedItem) {
        // Сброс предыдущего выбранного элемента
        if (selectedItem) {
            selectedItem->setFixedSize(76, 76);
            selectedItem->setText(QString("Item %1").arg(items.indexOf(selectedItem) + 1));
            labels[items.indexOf(selectedItem)]->setVisible(true);
        }

        // Устанавливаем новый выбранный элемент
        clickedItem->setFixedSize(108, 108);
        clickedItem->setText("Selected Item");
        selectedItem = clickedItem;

        // Скрываем заголовок выбранного элемента
        int index = items.indexOf(clickedItem);
        if (index != -1) {
            labels[index]->setVisible(false);
        }

        // Перемещаем выбранный элемент в начало
        itemsLayout->removeWidget(clickedItem);
        itemsLayout->insertWidget(0, clickedItem);

        // Перемещаем остальные элементы
        QVector<QPushButton*> newOrder;
        newOrder.append(clickedItem);
        for (int i = index + 1; i < items.size(); ++i) {
            newOrder.append(items[i]);
        }
        for (int i = 0; i < index; ++i) {
            newOrder.append(items[i]);
        }

        // Обновляем компоновку
        for (int i = 1; i < newOrder.size(); ++i) {
            itemsLayout->removeWidget(newOrder[i]);
            itemsLayout->addWidget(newOrder[i]);
        }
    }
}
