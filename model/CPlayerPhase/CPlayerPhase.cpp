#include "CPlayerPhase.h"
#include "PawnTypes/CPersonPawn.h"
#include "PawnTypes/CEnemyPawn.h"

void CPlayerPhase::Init(CWorld * world,CLocation * loadLocation)
{
    this->world = world;
    this->loadLocation = loadLocation;
    int personPawnAmmount = loadLocation->GetPersonAmmount();
    for(int i=0;i<personPawnAmmount;i++) {
//        personPawnList.push_back(new CPersonPawn);
//        personPawnList[personPawnList.size()-1]->Init(loadLocation->GetPerson(i));
    }
    int wildPawnAmmount;
    switch(loadLocation->GetLocationType())
    {
    case WILDS:
        wildPawnAmmount = 15;
    break;
    case VILLAGE:
        wildPawnAmmount = 10;
    break;
    case CITY:
        wildPawnAmmount = 5;
    break;
    }
    for(int i=0;i<wildPawnAmmount;i++) {
        //wildPawnList.push_back(new CEnemyPawn);
        //wildPawnList[wildPawnList.size()-1]->Init(loadLocation);
    }
    is_running = true;

}

void CPlayerPhase::MakeTurn()
{
    for(int i=0;i<personPawnList.size();i++) {
        CPawnAI pawnAI;
//        pawnAI.Init(personPawnList[i]->GetAIType());
//        pawnAI.MadeDesicion();
        SDecision pawnDesicion = pawnAI.GetDesicionResult();

    }
    for(int i=0;wildPawnList.size();i++) {
        CPawnAI pawnAI;
//        pawnAI.Init(wildPawnList[i]->GetAIType());
//        pawnAI.MadeDesicion();
        SDecision wpawnDecision = pawnAI.GetDesicionResult();
        if(!wpawnDecision.is_blocking && !wpawnDecision.interaction.existed && !wpawnDecision.is_parrying && !wpawnDecision.is_attacking) {
            switch(wpawnDecision.directionCode) {
            case UP:
//                wildPawnList[i]->MoveUp();
            break;
            case DOWN:
//                wildPawnList[i]->MoveDown();
            break;
            case RIGHT:
//                wildPawnList[i]->MoveRight();
            break;
            case LEFT:
//                wildPawnList[i]->MoveLeft();
            break;
            }
        } else if(wpawnDecision.interaction.existed) {

        } else if(wpawnDecision.is_attacking) {
            CPawn* pawnUnderAttack;
            cords tileUnderAttackCords = wildPawnList[i]->GetCurrentPosOnLocation();
            switch(wpawnDecision.directionCode) {
            case UP:
                tileUnderAttackCords.y--;
            break;
            case DOWN:
                tileUnderAttackCords.y++;
            break;
            case RIGHT:
                tileUnderAttackCords.x++;
            break;
            case LEFT:
                tileUnderAttackCords.x--;
            break;
            }
//            pawnUnderAttack = field.GetPawn(tileUnderAttackCords);
            if(pawnUnderAttack != nullptr) {
//                battleSystem.CalculateAttack(wildPawnList[i],pawnUnderAttack);
            }
        }
    }
}

void CPlayerPhase::Quit()
{
    for(int i=0;i<personPawnList.size();i++) {
//        personPawnList[i]->Unchain();
        delete personPawnList[i];
    }
    for(int i=0;i<wildPawnList.size();i++) {
        delete wildPawnList[i];
    }

}
