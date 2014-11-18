#ifndef WINCONFIG_H
#define WINCONFIG_H

#include <QWidget>
//#include "UI.h"
#include "cAddRemove.h"
#include "cConfig.h"

namespace Ui {
class winConfig;
}

class winConfig : public QWidget
{
    Q_OBJECT

public:
    explicit winConfig(QWidget *parent = 0);
    ~winConfig();

public slots:
    void on_bAbort_clicked();

private:
    Ui::winConfig *ui;
};

#endif // WINCONFIG_H
