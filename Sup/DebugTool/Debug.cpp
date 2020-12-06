#include "Debug.h"

void CDebug::Init(int currentDebugType)
{
    this->currentDebugType = currentDebugType;
}

void CDebug::Print(string line, int type)
{
    if(currentDebugType == type) {
//        printf(line.c_str());
    }
}
