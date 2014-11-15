#include "winMain.h"
#include "ui_winMain.h"
#include <iostream>

winMain::winMain(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::winMain)
{
    ui_->setupUi(this);
}
winMain::~winMain()
{
    delete ui_;
}

// Set controllers
int winMain::setCAddRemove(cAddRemove *ptr)
{
    cAddRemovePtr_ = ptr;
    return 0;
}

int winMain::setCConfig(cConfig *ptr)
{
    cConfigPtr_ = ptr;
    return 0;
}


// Getters, not used yet!
Ui::winMain * winMain::getUi() const
{
    return ui_;
}

// Slots
void winMain::on_bAddRemove_clicked()
{
    cAddRemovePtr_->menuAddRemove();
}

void winMain::on_bConfig_clicked()
{
    cConfigPtr_->menuConfig();
}
