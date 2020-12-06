#ifndef CACTION_H_INCLUDED
#define CACTION_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define INCREMENT true
#define DICREMENT false

class CAction {
public:
    CAction() {}
    CAction(int codeName,int defaultValue,bool increment);

    //methods
    void Click();

    //setters
    void SetCodeName(int codeName) { this->codeName = codeName; }
    void SetHandledValue(int value) { handledValue = value; }
    void SetTwinAction(CAction* tAction);
    //getters
    int GetCodeName() { return codeName; }
    int GetHandledValue() { return handledValue; }
    CAction* GetTwinAction() { return twinAction; }
    bool haveTwin() { if(twinAction == nullptr) return false; else return true;  }
protected:
    int codeName;
    int handledValue;
    CAction * twinAction;
    bool increment;
};

#endif // CACTION_H_INCLUDED
