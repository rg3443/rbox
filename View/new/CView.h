#ifndef CVIEW_H_INCLUDED
#define CVIEW_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../model/CModel.h"
#include "GSDL2.h"
#include "CBRender/CBRender.h"
#include "scenes/CBaseScene.h"
#include "../../pcgGlobal.h"
#include "Input/CActionList.h"

class CView {
public:
    CView() {}
    void Init(CModel * model,CActionList * actionList);
    void _InitScenes();
    void DrawScene(int sceneCode);


    //setters

    //getters
    CBRender* GetAdvanceRender() { return &render; }
    SDLGlobal* GetSDLGlobal() { return &sdlGlobal; }
    CBaseScene* GetScene(int id) { return &sceneList[id]; }
    CBaseScene* GetSceneByCode(int sceneCode);
    int GetSceneSize() { return sceneList.size(); }

    //SCENES
    void _InitMainScene();
    void _InitTestScene();
    void _InitPersosShowScene();
    void _InitGameScene();
    void _InitSettingsScene();

protected:
    CModel * model;
    SDLGlobal sdlGlobal;
    CBRender render;
    vector<CBaseScene> sceneList;
    CActionList* actionList;
private:
    //leverage
    void _printSceneAfterInit();
};

#endif // CVIEW_H_INCLUDED
