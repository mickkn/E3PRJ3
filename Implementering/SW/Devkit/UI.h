#ifndef UI_H
#define UI_H

#include <QWidget>
#include "winMain.h"
#include "winConfig.h"

class UI
{
public:
    UI();
    ~UI();

    int setCAddRemove(cAddRemove *);
    cAddRemove * getCAddRemove();
    int setCConfig(cConfig *);
    cConfig * getCConfig();

    QWidget * getCurrent();

private:
    // Window QWidgets
    winMain winMainObj_;
    winConfig winConfigObj_;

    QWidget * current_;

    // Controller pointers
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
};

#endif // UI_H
