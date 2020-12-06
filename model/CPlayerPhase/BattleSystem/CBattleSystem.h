#ifndef CBATTLESYSTEM_H_INCLUDED
#define CBATTLESYSTEM_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;
#include "../CPawn.h"

class CBattleSystem {
public:
    CBattleSystem() {}
    void Init();
    void CalculateAttack(CPawn* attackingPawn,CPawn* deffendingPawn);

protected:

};


#endif
