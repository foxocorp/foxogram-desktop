#ifndef MULTILAYERWIDGET_H
#define MULTILAYERWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QGraphicsBlurEffect>

class MultiLayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultiLayerWidget(QWidget *parent = nullptr);
    ~MultiLayerWidget();

    void setModalBackgroundBlurred(bool state);
    void setActiveWidget(QWidget *widget, bool isModal);

    bool getBlurEnabled() const;

protected:
    int addWidget(QWidget *w);

    QWidget *getLastStackWidget();

private:
    std::unique_ptr<QStackedLayout> stackedLayout;

    QGraphicsBlurEffect *blurEffect;

    bool blurEnabled = false;
    bool activeIsModal = false;

    QGraphicsBlurEffect *createBlurEffect();
    void refreshInactiveStack();
};

#endif // MULTILAYERWIDGET_H
