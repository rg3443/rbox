#include "cmenusystem.h"

CMenuSystem::CMenuSystem()
{

}

void CMenuSystem::Init()
{
    currentMenuId = 0;
    this->CreateMenu(0);
    this->_GetLast()->AddButton("test",cords(10,10),cords(30,30),1);
    this->_GetLast()->AddText("yyeeee boi",cords(30,30));
    this->CreateMenu(1);
    this->_GetLast()->AddText("working",cords(30,30));

}

void CMenuSystem::CreateMenu(int id)
{
    menuList.push_back(CMenu(id));
}
