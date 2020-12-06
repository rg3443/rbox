#include "CPawnAI.h"

void CPawnAI::Init(CPawn * pawn, vector<vector<CTile*>> tilesAround)
{
    this->AITypeCode = pawn->GetAIType();
    switch(pawn->GetAIType())
    {
        /*
    PANIC,
    AGGRESIVE,
    DEFFENDING,
    NEUTRAL,
    COMRAD*/
    case AGGRESIVE:
        vector<cords> enemyTilesList;
        for(int y=0;y<tilesAround.size();y++) {
            for(int x=0;x<tilesAround[y].size();x++) {
                if(tilesAround[y][x]->GetStatus() == CONTAINS_PAWN){
                    //switch(gCalcDirectionToThePoint(cords(),cords))
                }
            }
        }
    break;
    }
}
