#ifndef CMENUSYSTEM_H
#define CMENUSYSTEM_H

#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include "cmenu.h"

class CMenuSystem {
public:
    CMenuSystem();
    void Init();
    void SetCurrentMenu(int newMenuId) { currentMenuId = newMenuId; }

    int GetCurrentMenuId() { return currentMenuId; }
    int GetMenuSize() { return menuList.size(); }
    CMenu* GetMenu(int id) { return &menuList[id]; }

    //
    void CreateMenu(int id);
    CMenu* _GetLast() { return &menuList[menuList.size()-1]; }
private:
    int currentMenuId;
    vector<CMenu> menuList;
};

#endif // CMENUSYSTEM_H
