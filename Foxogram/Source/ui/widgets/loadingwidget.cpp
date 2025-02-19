#include "loadingwidget.h"
#include "ui/tools/giflabelloader.h"

#include <QLayout>

namespace {
    static const QSize windowSize = {
        350, 350
    };
    static const auto imagePath = ":/images/loading/pawprints.gif";
    static const auto pawsLoadingScale = 75;
}

LoadingWidget::LoadingWidget(QWidget *parent) : QWidget(parent)
{
    setObjectName("LoadingWidget");
    setWindowFlag(Qt::FramelessWindowHint);
    setFixedSize(windowSize);
    setStyleSheet("#LoadingWidget { background-color: #0A0A0A; }");

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    // Logo
    QHBoxLayout *logoLayout = new QHBoxLayout();
    logoLabel = new QLabel(this);
    logoLabel->setMaximumSize(150, 150);
    logoLabel->setPixmap(QPixmap(":/icons/logo.svg"));
    logoLabel->setScaledContents(true);
    logoLabel->setAlignment(Qt::AlignCenter);

    logoLayout->addWidget(logoLabel);
    mainLayout->addLayout(logoLayout);

    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    // Loading anim
    QHBoxLayout *animLayout = new QHBoxLayout();
    animLayout->setSpacing(0);

    animLayout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    animLabel = new QLabel(this);
    animLabel->setAlignment(Qt::AlignCenter);
    animLayout->addWidget(animLabel);

    animLayout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    mainLayout->addLayout(animLayout);

    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    setLayout(mainLayout);

    makeLoadingAnimation();
}

LoadingWidget::~LoadingWidget() = default;

void LoadingWidget::makeLoadingAnimation()
{
    Tools::GifLabel::create(imagePath, animLabel, pawsLoadingScale);
}

void LoadingWidget::proceedLoading()
{
    emit loaded();
}
