#ifndef CPAWNAI_H_INCLUDED
#define CPAWNAI_H_INCLUDED


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../../pcgGlobal.h"
#include "../CPawn.h"
#include "../Field/CField.h"
#include "../Field/CMetaTile.h"
#include "../GPlayerPhase.h"

/*
**  CPawnAI - класс отвечающий за принимаемые решения, определенной пешки
**  SDecision - структура содержащая данные о принятом решении
**  SStartedInteraction - структура содержащая данные о наличии и id взаимодействия
**  EAITypes - список типов поведения ИИ.
*/

class CPawnAI {
public:
    CPawnAI() {}
    void Init(CPawn * pawn, vector<vector<CTile*>> tilesAround);
    void MadeDesicion();
    SDecision GetDesicionResult() { return finalDesicion; }
protected:
    int AITypeCode; // EAITypes
    SDecision finalDesicion;
};

#endif
