#include "regionsview.h"
#include "ytregions.h"
#include "mainwindow.h"

RegionsView::RegionsView(QWidget *parent) : QWidget(parent) {
    QBoxLayout *l = new QVBoxLayout(this);
    l->setMargin(30);
    l->setSpacing(30);

    layout = new QGridLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    l->addLayout(layout);

    addRegion(YTRegions::worldwideRegion());
    foreach(YTRegion region, YTRegions::list())
        addRegion(region);

    doneButton = new QPushButton(tr("Done"));
    doneButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    doneButton->setDefault(true);
    doneButton->setProperty("custom", true);
    doneButton->setProperty("important", true);
    doneButton->setProperty("big", true);
    connect(doneButton, SIGNAL(clicked()), MainWindow::instance(), SLOT(goBack()));
    l->addWidget(doneButton, 0, Qt::AlignCenter);
}

void RegionsView::addRegion(const YTRegion &region) {
    QPushButton *button = new QPushButton(region.name);
    button->setProperty("regionId", region.id);
    button->setCheckable(true);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    button->setFocusPolicy(Qt::StrongFocus);
    button->setIcon(YTRegions::iconForRegionId(region.id));
    connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
    const int i = layout->count();
    static const int rows = 10;
    layout->addWidget(button, i % rows, i / rows);
}

void RegionsView::appear() {
    doneButton->setFocus();

    QString currentRegionId = YTRegions::currentRegionId();
    for (int i = 0; i < layout->count(); i++) {
        QLayoutItem *item = layout->itemAt(i);
        QPushButton *b = static_cast<QPushButton*>(item->widget());
        QString regionId = b->property("regionId").toString();
        b->setChecked(currentRegionId == regionId);
    }
}

void RegionsView::buttonClicked() {
    QObject* o = sender();
    QString regionId = o->property("regionId").toString();
    YTRegions::setRegion(regionId);
    emit regionChanged();
    doneButton->click();

    // uncheck other buttons
    /*
    for (int i = 0; i < layout->count(); i++) {
        QLayoutItem *item = layout->itemAt(i);
        QPushButton *b = static_cast<QPushButton*>(item->widget());
        if (b != o && b->isChecked()) b->setChecked(false);
    }
    */
}
