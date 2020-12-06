#ifndef CMENULIST_H_INCLUDED
#define CMENULIST_H_INCLUDED


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../pcgGlobal.h"
#include "../CGlobalModel.h"

class CMenuList {
public:
    CMenuList() {}
    void Init();
protected:
    vector<int> menuList;

};

#endif // CMENULIST_H_INCLUDED
