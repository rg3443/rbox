#ifndef CENEMYPAWN_H_INCLUDED
#define CENEMYPAWN_H_INCLUDED


/*
**  CEnemyPawn - класс пешка, которая является "наполнением" мира, не имеющим
**  отношения к CWorld
**  не является уникальным обьектом.
*/


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../../pcgGlobal.h"
#include "../../../model/CWorld/CLocation.h"

class CEnemyPawn {
public:
    CEnemyPawn() {}
    void Init(CLocation * spawnLocation);

protected:
    CLocation * spawnLocation;
};

#endif // CBASEMODELOBJECT_H_INCLUDED
