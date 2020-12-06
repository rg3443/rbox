#ifndef CPERSONPAWN_H_INCLUDED
#define CPERSONPAWN_H_INCLUDED


/*
**  CPersonPawn - класс пешка, которая представляет подвязанную к себе персону
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
#include "../../../pcgGlobal.h"
#include "../CPawn.h"
#include "../../../model/CWorld/CPerson.h"


class CPersonPawn : public CPawn {
public:
    CPersonPawn() {}
    void Init(CPerson * person);
    void Unchain();

protected:
    CPerson* person;

};

#endif // CBASEMODELOBJECT_H_INCLUDED
