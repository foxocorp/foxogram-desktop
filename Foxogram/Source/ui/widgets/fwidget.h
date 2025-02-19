#ifndef FWIDGET_H
#define FWIDGET_H

#include <QWidget>
#include "multilayerwidget.h"

class FWidget : public MultiLayerWidget
{
    Q_OBJECT
public:
    explicit FWidget(QWidget *parent = nullptr);
};

#endif // FWIDGET_H
