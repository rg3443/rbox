#ifndef CPRESENTER_H
#define CPRESENTER_H

#include "../model/CModel.h"
#include "../View/new/CView.h"
#include "../View/new/Input/CInput.h"

class CPresenter
{
public:
    CPresenter();
    void Init();
    void Run();
    void TestRun();
    void Quit();

    void CheckSceneInput(int sceneCode,int mx,int my);
    void DrawCurrentScene();
private:
    CModel model;
    CView view;
    CInput input;
    //MainWindow * view;

};

#endif // CPRESENTER_H
