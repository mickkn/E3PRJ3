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


// Getters, not used yet!
Ui::winMain * winMain::getUi() const
{
    return ui_;
}

// Slots
void winMain::on_bAddRemove_clicked()
{

}

void winMain::on_bConfig_clicked()
{
   // cConfigPtr_->menuConfig();
}
