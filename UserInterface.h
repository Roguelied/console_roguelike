#ifndef CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
#define CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H

#include "Utility.h"

class UserInterface {
private:

public:
    int StartMenu();
    string ClassMenu();
    void OpenInventory(vector<InvSlot> Inventory);
};

#endif //CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
