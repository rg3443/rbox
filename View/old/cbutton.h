#ifndef CBUTTON_H
#define CBUTTON_H

#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include "../pcgGlobal.h"
#include <QRect>

class CButton {
public:
    CButton();
    CButton(string text,cords p1,cords p2,int direction) { this->Init(text,p1,p2,direction); }
    void Init(string text,cords p1,cords p2,int direction);

    int GetDirection() { return menuIdDirection; }
    string GetText() { return text; }
    QRect GetPos() { return QRect(QPoint(point1.x,point1.y),QPoint(point4.x,point4.y)); }
private:
    cords point1,point4;
    int menuIdDirection;
    string text;
};

#endif // CBUTTON_H
