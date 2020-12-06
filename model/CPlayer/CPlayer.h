#ifndef CPLAYER_H_INCLUDED
#define CPLAYER_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../CBaseModelObject.h"
//#include "../Creatures/CBaseCreature.h"

class CPerson;

class CPlayer {
public:
    CPlayer() { playerPerson = nullptr; }
    void Init( ) {}

    //getters
    CPerson* GetPerson() { return playerPerson; }
    //setters
    void SetPerson(CPerson* val) { playerPerson = val; }

protected:
    CPerson * playerPerson;
};

#endif // CPLAYER_H_INCLUDED
