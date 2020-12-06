#ifndef CMETATILE_H_INCLUDED
#define CMETATILE_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;
#include "../../CPlayer/CPlayer.h"
#include "../../CWorld/CLocation.h"
//#include "../PawnAI/CPawnAI.h" //todo: це нужно только для типа интелекта, поэтому тип куда-то в глобальное нужно перенести
#include "../GPlayerPhase.h"

enum ETileStatus {
    FREE,
    BLOCKED,
    CONTAINS_PAWN

};

class CTile {
public:
    CTile() {}
    void Init(int status, int hight, int texCode) {
        this->status = status;
        this->hight = hight;
        this->textureCode = texCode;
    }

    //setters
    void SetStatus(int status) { this->status = status; }
    void SetHight(int hight) { this->hight = hight; }
    void SetTextureCode(int texCode) { textureCode = texCode; }
    void SetObjectCode(int objCode) { objectCode = objCode; }

    //getters
    int GetStatus() { return status; }
    int GetHight() { return hight; }
    int GetTextureCode() { return textureCode; }
    int GetObjectCode() { return objectCode; }

protected:
    int posx,posy;
    int status;         // ETileStatus
    int hight;          // 0-4
    int textureCode;    // ETextureCodeName
    int objectCode;     // todo: field from CBaseIngameObject or replace with object pointer
};


#endif // CMETATILE_H_INCLUDED
