#ifndef CPLAYERPHASE_H_INCLUDED
#define CPLAYERPHASE_H_INCLUDED

/*
**  CPlayerPhase - класс отвечающий за "пользовательскую" часть хода программы
*/

#include <iostream>
#include <stdio.h>
using namespace std;
#include "Field/CField.h"
#include "../CPlayer/CPlayer.h"
#include "../CWorld/CLocation.h"
#include "../CWorld/CWorld.h"
#include "PawnAI/CPawnAI.h"
#include "CPawn.h"

class CPlayerPhase {
public:
    CPlayerPhase() {}
    void Init(CWorld * world,CLocation * loadLocation);
    void MakeTurn();
    void Quit();

protected:
    bool is_running;
    CWorld * world;
    CField field;
    CLocation * loadLocation;
    vector<CPawn*> personPawnList,wildPawnList;

};

#endif
