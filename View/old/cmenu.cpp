#include "cmenu.h"

CMenu::CMenu()
{

}

void CMenu::Init(int id)
{
    this->id = id;
}

void CMenu::AddButton(string text, cords p1, cords p2,int direction)
{
    buttonList.push_back(CButton(text,p1,p2,direction));
}

void CMenu::AddTexture(CTexture *texture)
{
    textureList.push_back(texture);
}

void CMenu::AddText(string text, cords pos)
{
    textList.push_back(SText(text,pos));
}
