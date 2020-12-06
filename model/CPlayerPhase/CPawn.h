#ifndef CPAWN_H_INCLUDED
#define CPAWN_H_INCLUDED

/*
**
**
**
**
**
**
**
**
**
**
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../pcgGlobal.h"


/*
    typical stats(typical human male)
    hp : 100
    def : 5|5|5
    spd : 10
    agy : 25% dodge chance
    atk : 0|0|15-20
*/

struct SDamage {
    float slice,pierce,blunt;
    SDamage() {}
    SDamage(float sli,float pie,float blu) {
        slice = sli;
        pierce = pie;
        blunt = blu;
    }
    void Clear() {
        slice = 0;
        pierce = 0;
        blunt = 0;
    }
};

struct SPawnStats {
    int spd,agy;
    float hp;
    SDamage atkDmg,def;
    SPawnStats() {}
    SPawnStats(float hp_, SDamage def_, int spd_, int agy_,SDamage dmg) {
        hp = hp_;
        def = def_;
        spd = spd_;
        agy = agy_;
        atkDmg = dmg;
    }
};

struct SPawnStatus {
    bool is_blocking,is_attacking,is_parrying;
};

class CPawn {
public:
    CPawn() {}
    SPawnStats* GetStats() { return &stats; }
    void SetStats(SPawnStats pawnStats) { stats = pawnStats; }
    void SetCurrentPosOnLocation(cords pos) { currentPosOnLocation = pos; }
    void SetLocationPos(cords pos) { locationPos = pos; }
    cords GetCurrentPosOnLocation() { return currentPosOnLocation; }
    int GetX() { currentPosOnLocation.x; }
    int GetY() { currentPosOnLocation.y; }

    //movemant
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void ModeRight();

    //AI
    void SetAIType(int typeCode) { AIArchitype = typeCode; }
    int GetAIType() { return AIArchitype; }
    void SetPawnStatus(SPawnStatus pawnStatus) { this->pawnStatus = pawnStatus; }
    SPawnStatus* GetPawnStatus() { return &pawnStatus; }
    void SetSubgroupCode(int code) { subgroupCode = code; }
    int GetSubgroupCode() { return subgroupCode; }

protected:
    SPawnStats stats; // изменяемые характеристики пешки
    cords currentPosOnLocation,locationPos; // координаты пешки на локации, координаты локации
    SPawnStatus pawnStatus; // статусы пешки
    int subgroupCode;
    int AIArchitype; // тип поведения пешки
};

#endif //
