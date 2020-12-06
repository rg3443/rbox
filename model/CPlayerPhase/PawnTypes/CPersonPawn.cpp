#include "CPersonPawn.h"

void CPersonPawn::Init(CPerson * person)
{
    this->person = person;
    //stats = person->GenerateStats();  //todo: <-- this func

}

void CPersonPawn::Unchain()
{
    //person->GenerateChangesFromStats(stats);

}
