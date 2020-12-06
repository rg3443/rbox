#include "trand.h"

trand::trand(int minValue,int maxValue)
{
    this->Init(minValue,maxValue);
}

void trand::Init(int minValue,int maxValue)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
    //this->UpdateSeed();
}

void trand::UpdateSeed()
{
    srand((unsigned) time(0));
    //printf("seed updated\n");
}

int trand::_rand()
{
    int num = rand() % (maxValue-minValue) + minValue;
    return num;
}

int trand::_trand()
{
    this->UpdateSeed();
    int num = rand() % (maxValue-minValue) + minValue;
    return num;
}
