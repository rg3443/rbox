#include "CAction.h"

CAction::CAction(int codeName,int defaultValue,bool increment)
{
    this->codeName = codeName;
    handledValue = defaultValue;
    twinAction = nullptr;
    this->increment = increment;
}

void CAction::Click()
{
    if(increment) {
        handledValue++;
    } else {
        handledValue--;
    }
}

void CAction::SetTwinAction(CAction* tAction)
{
    twinAction = tAction;
    twinAction->SetHandledValue(this->handledValue);
    twinAction->SetTwinAction(this);
}
