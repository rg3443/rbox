#ifndef CMENU_H
#define CMENU_H

#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include "../pcgGlobal.h"
#include "cbutton.h"
#include "ctexturesystem.h"

struct SText {
    string text;
    cords pos;
    int w,h;
    SText() {}
    SText(string text_,cords pos_) {
        text = text_;
        pos = pos_;
        h = 20;
        w = text_.size() * 6;
    }
    int GetW() {
        return w;
    }
    int GetH() {
        return h;
    }
};

class CMenu {
public:
    CMenu();
    CMenu(int id) { this->Init(id); }
    void Init(int id);

    void AddButton(string text,cords p1,cords p2,int direction);
    void AddTexture(CTexture* texture);
    void AddText(string text,cords pos);

    CButton* GetButton(int id) { return &buttonList[id]; }
    CTexture* GetTexture(int id) { return textureList[id]; }
    SText* GetText(int id) { return &textList[id]; }

    int GetButtonSize() { return buttonList.size(); }
    int GetTextureSize() { return textList.size(); }
    int GetTextSize() { return textList.size(); }
private:
    int id;
    vector<CButton> buttonList;
    vector<CTexture*> textureList;
    vector<SText> textList;
};

#endif // CMENU_H
