#include "itemselector.h"
#include <QRandomGenerator>

ItemSelector::ItemSelector(QWidget *parent)
    : QWidget(parent), selectedItem(nullptr), itemCount(5) {

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 5, 5, 5);

    itemsLayout = new QHBoxLayout();
    itemsLayout->setContentsMargins(5, 5, 5, 5);

    // Создаем кнопки и метки, добавляем их в отдельные QVBoxLayout
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
        itemLayouts.append(buttonLayout); // Сохраняем макет для последующего использования
    }


    mainLayout->addLayout(itemsLayout);
    setLayout(mainLayout);
}

void ItemSelector::selectItem() {
    QPushButton *clickedItem = qobject_cast<QPushButton*>(sender());
    if (clickedItem) {
        // Сброс предыдущего выбранного элемента
        if (selectedItem) {
            int prevIndex = items.indexOf(selectedItem);
            selectedItem->setFixedSize(76, 76);
            selectedItem->setText(QString("Item %1").arg(prevIndex + 1));
            labels[prevIndex]->setVisible(true);
        }

        // Устанавливаем новый выбранный элемент
        clickedItem->setFixedSize(108, 108);
        clickedItem->setText("Selected Item");
        selectedItem = clickedItem;

        // Скрываем заголовок выбранного элемента
        int index = items.indexOf(clickedItem);
        if (index != -1) {
            labels[index]->setVisible(false);

            // Перемещаем весь QVBoxLayout с кнопкой и меткой в начало
            QVBoxLayout *selectedLayout = itemLayouts[index];
            itemsLayout->removeItem(selectedLayout);
            itemsLayout->insertItem(0, selectedLayout);
        }
    }
}
