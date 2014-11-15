#include <QApplication>
#include "winMain.h"    // UI controller

// Controllers
#include "caddremove.h"
#include "cconfig.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create controllers
    cAddRemove cAddRemoveObj;
    cConfig cConfigObj;

    // Create UI
    winMain w;
    w.setCAddRemove(&cAddRemoveObj);
    w.setCConfig(&cConfigObj);
    w.show();
    return a.exec();
}
