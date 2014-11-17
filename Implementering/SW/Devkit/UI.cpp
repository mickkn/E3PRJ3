#include "UI.h"

UI::UI()
{
    current_ = &winMainObj_;
}

UI::~UI()
{

}

// Getters
QWidget * UI::getCurrent()
{
    return current_;
}

// Setters and getters
int UI::setCAddRemove(cAddRemove *ptr)
{
    cAddRemovePtr_ = ptr;
    return 0;
}
cAddRemove * UI::getCAddRemove()
{
    return cAddRemovePtr_;
}

int UI::setCConfig(cConfig *ptr)
{
    cConfigPtr_ = ptr;
    return 0;
}
cConfig * UI::getCConfig()
{
    return cConfigPtr_;
}
