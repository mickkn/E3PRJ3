#ifndef WINMAIN_H
#define WINMAIN_H

#include <QWidget>
#include "caddremove.h"
#include "cconfig.h"

namespace Ui {
class winMain;
}

class winMain : public QWidget
{
    Q_OBJECT

public:
    explicit winMain(QWidget *parent = 0);
    ~winMain();

    Ui::winMain * getUi() const;

    int setCAddRemove(cAddRemove *);
    int setCConfig(cConfig *);

public slots:
    void on_bAddRemove_clicked();
    void on_bConfig_clicked();


private:
    Ui::winMain *ui_;
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
};

#endif // WINMAIN_H
