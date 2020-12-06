#ifndef TRAND_H_INCLUDED
#define TRAND_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;
#include <random>
#include <ctime>


class trand {
public:
    trand() {}
    trand(int minValue,int maxValue);
    void Init(int minValue,int maxValue);
    void UpdateSeed(); // updates seed
    int _rand();
    int _trand();


protected:
    int minValue,maxValue;
};

#endif // TRAND_H_INCLUDED
