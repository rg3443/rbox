#include "CInput.h"

void CInput::Init(CModel * model,CView * view)
{
    this->view = view;
    this->sdlGlobal = view->GetSDLGlobal();
    this->model = model;
}

SInputResult CInput::HandleSceneInput_(int mx,int my)
{
    SInputResult result;
    this->currentSceneCode = model->GetCurrentSceneCode();
    CBaseScene* scene = view->GetSceneByCode(currentSceneCode);
    for(int buttid=0;buttid<scene->GetButtonSize();buttid++) {
        SButton button = scene->GetButton(buttid);
        if(button.sqrFld.IsInside(SPoint(mx,my))) {
            result.type = button.type;
            result.code = button.directionCode;
        }
    }
    return result;
}

SInputResult CInput::HandleSceneInput(int mx,int my)
{
    this->currentSceneCode = model->GetCurrentSceneCode();
    SCurrentPlayData gameData = model->GetGameStatus();
            //only BUTTON type components squares must be checked
            //BUT! buttons can be contained in menuboxes etc
            CBaseScene* currentScene = view->GetScene(currentSceneCode);
            //printf(currentScene->GetDescription().c_str());
                //printf("were fucking menusrgbBUIO;wio\n");
                //int size__s = currentScene->GetButtonSize();
                //printf("buttons size:%d\nmenubox size:%d\n",currentScene->GetButtonSize(),currentScene->GetMenuBoxSize());

            if(currentScene->isButtonEmpty())
            for(int buttid=0;buttid<currentScene->GetButtonSize();buttid++) {
                SButton* currentButt = currentScene->GetButtonPointer(buttid);

//                printf("1");

                SSquare buttSqr = currentButt->sqrFld;

//                printf("2");

//                printf("\tmosue x%d|y%d\n",mx,my);
                PrintSSquare(buttSqr);
                if(mx > buttSqr.ulPoint.x && mx < buttSqr.drPoint.x && my > buttSqr.ulPoint.y && my < buttSqr.drPoint.y) {
                    //button was clicked
//                    printf("button clicked\n");
                    if(currentButt->type == SCENE_DIRECTION) {
                        //setting new scene to render
                        gameData.SetCurrentScene(currentButt->directionCode);
                    } else if(currentButt->type == ACTION_DIRECTION) {
                        //do some action //todo: CAction that will say what must be done
//                        printf("ITS AN ACTION BUTTON\n");
                        actionList.GetActionByCodeName(currentButt->directionCode)->Click();
                        view->_InitScenes();
                    }
                }
            }
    model->SetGameStatus(gameData);
}

