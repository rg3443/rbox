#ifndef CINPUT_H_INCLUDED
#define CINPUT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#include "SDL.h"
#include "../../../model/CModel.h"
#include "../GSDL2.h"
#include "../CView.h"
#include "../scenes/CBaseScene.h"
#include "../scenes/GSceneComponents.h"
#include "CActionList.h"

struct SInputResult {
    int type; //ERedirectionType
    int code;
    SInputResult() {}
    SInputResult(int type_,int code_) {
        type = type_;
        code = code_;
    }
};


class CInput {
public:
    CInput() {}
    void Init(CModel * model,CView * view);

    //methods
    SInputResult HandleSceneInput(int mx,int my);
    SInputResult HandleSceneInput_(int mx,int my);

    //getters
    SDL_Event* GetEventContainer() { return event; }
    CActionList* GetActionList() { return &actionList; }
    //setters
    void SetEvent(SDL_Event * event) { this->event = event; }
protected:
    int currentSceneCode; //ESceneCode
    SDL_Event * event;
    SDLGlobal* sdlGlobal;
    CModel * model;
    CView * view;

    CActionList actionList;
};

#endif // CINPUT_H_INCLUDED
