#include <QApplication>
#include "UI.h"    // UI controller

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
    UI UIObj;
    UIObj.setCAddRemove(&cAddRemoveObj);
    UIObj.setCConfig(&cConfigObj);
    UIObj.getCurrent()->show();
    return a.exec();
}
