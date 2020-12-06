#ifndef CACTIONLIST_H_INCLUDED
#define CACTIONLIST_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#include "CAction.h"

class CActionList {
public:
    CActionList() {}
    void Init();

    //leverage
    void AddAction(CAction newAction);

    //getters
    CAction* GetActionByID(int id);
    CAction* GetActionByCodeName(int codeName);

    //setters

protected:
    vector<CAction> _list;
};

#endif // CACTIONLIST_H_INCLUDED
