#ifndef CFIELD_H_INCLUDED
#define CFIELD_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;
#include "../../CPlayer/CPlayer.h"
#include "../../CWorld/CLocation.h"
#include "CMetaTile.h"
#include <vector>


class CField {
public:
    CField() {}
    void Init();


protected:
    vector<vector<CTile>> tileMatrix;

};

#endif
