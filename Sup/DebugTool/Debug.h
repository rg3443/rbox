#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

enum EDebugType {
    DETAILED,
    COMMUNIS
};

class CDebug {
public:
    CDebug() {}
    void Init(int currentDebugType);
    void Print(string line,int type);
protected:
    int currentDebugType;
};

#endif // DEBUG_H_INCLUDED
