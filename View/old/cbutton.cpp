#include "cbutton.h"

CButton::CButton()
{

}

void CButton::Init(string text,cords p1, cords p2, int direction)
{
    point1 = p1;
    point4 = p2;
    menuIdDirection = direction;
    this->text = text;
}
