#include "multilayerwidget.h"

namespace {
constexpr int defaultModalBlurStrength = 30;
}

MultiLayerWidget::MultiLayerWidget(QWidget *parent) : QWidget{parent}
{
    stackedLayout = std::make_unique<QStackedLayout>(this);
    stackedLayout->setStackingMode(QStackedLayout::StackAll);
}

MultiLayerWidget::~MultiLayerWidget()
{
    delete blurEffect;
}

void MultiLayerWidget::setModalBackgroundBlurred(bool state)
{
    blurEnabled = state;
}

void MultiLayerWidget::setActiveWidget(QWidget *widget, bool isModal = false)
{
    activeIsModal = isModal;

    if (getLastStackWidget() != widget)
        stackedLayout->addWidget(widget);

    stackedLayout->setCurrentWidget(widget);

    connect(widget, &QObject::destroyed, this, [=]() {
        stackedLayout->setCurrentIndex(stackedLayout->count() - 1);
        stackedLayout->removeWidget(widget);

        refreshInactiveStack();
    });

    // Set focus to active widget
    if (widget)
        widget->setFocus();

    refreshInactiveStack();
}

int MultiLayerWidget::addWidget(QWidget *w)
{
    return stackedLayout->addWidget(w);
}

QWidget *MultiLayerWidget::getLastStackWidget()
{
    int index = stackedLayout->count() - 1;

    return index > 0 ? stackedLayout->widget(index) : nullptr;
}

bool MultiLayerWidget::getBlurEnabled() const
{
    return blurEnabled;
}

QGraphicsBlurEffect *MultiLayerWidget::createBlurEffect()
{
    blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(defaultModalBlurStrength);

    return blurEffect;
}

void MultiLayerWidget::refreshInactiveStack()
{
    for (int i = 0; i < stackedLayout->count(); ++i) {
        bool current = stackedLayout->currentWidget() == stackedLayout->widget(i);

        stackedLayout->widget(i)->setGraphicsEffect(!current && activeIsModal && blurEnabled ? createBlurEffect() : nullptr);
        stackedLayout->widget(i)->setDisabled(!current);
    }
}
