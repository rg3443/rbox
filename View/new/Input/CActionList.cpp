#include "CActionList.h"

void CActionList::Init()
{

}

void CActionList::AddAction(CAction newAction)
{
    _list.push_back(newAction);
}

CAction* CActionList::GetActionByID(int id)
{
    try {
        if(!id < _list.size()) {
            throw "\tEROR:(00012)\n";
        } else return &_list[id];

    }
    catch(const char* eror) { printf(eror); }
}

CAction* CActionList::GetActionByCodeName(int codeName)
{
    for(int i=0;i<_list.size();i++) {
        if(_list[i].GetCodeName() == codeName) {
            return &_list[i];
        }
    }

}
