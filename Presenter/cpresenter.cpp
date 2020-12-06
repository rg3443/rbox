#include "cpresenter.h"

CPresenter::CPresenter()
{

}

void CPresenter::Init()
{
    model.Init();
printf("model init done\n");
    input.Init(&model,&view);
printf("input init done\n");
    view.Init(&model,input.GetActionList());
printf("view init done\n");
}

void CPresenter::Run()
{
    for(int i=0;i<10;i++)
        model.GetWorld()->_MadeTurn(i);
}

void CPresenter::TestRun()
{
//    printf("start run\n");
    SDL_Event inputEvent;
    input.SetEvent(&inputEvent);
//    printf("\ttest run starts\n");
    while(!model.GetGameStatus().quit)
    {
        this->DrawCurrentScene();
        if(SDL_WaitEvent(&inputEvent) != 0) {
            if(inputEvent.type == SDL_QUIT) {
                model.SetQuit(true);
            }
            if(inputEvent.type == SDL_MOUSEBUTTONDOWN) {
                int mx,my;
                SDL_GetMouseState(&mx,&my);
                this->CheckSceneInput(model.GetCurrentSceneCode(),mx,my);
            }
        }

    }
}

void CPresenter::CheckSceneInput(int sceneCode,int mx,int my)
{
    SInputResult inputResult;
    //todo: must have1!!!!!!1
    // ÈÍÏÓÒ ÄÎËÆÅÍ ÂÎÇÂÐÀÙÀÒÜ ÐÅÇÓËÜÒÀÒ ÑÂÎÅÉ ÐÀÁÎÒÛ ÂÂÈÄÅ ÑÒÐÓÊÒÓÐÛ Â ÊÎÒÎÐÎÉ ÁÓÄÅÒ ÃÎÂÎÐÈÒÑß ÊÀÊÎÉ ÒÈÏ ÈÍÏÓÒÀ(ÊÓÄÀ ÁÛËÎ ÍÀÆÀÒÎ, ÒÎÁÈØÜ ÊÀÊÎÉ ÒÈÏ ÊÍÎÏÊÈ)
    // È ÊÀÊÎÉ ÊÎÄ ÄÅÉÑÒÂÈß, ÅÑËÈ ÝÒÎ ÐÅÄÈÐÅÊØÍ ÒÎ ÊÎÄ ÄÈÐÅÊÒ ÌÅÍÞ, À ÅÑËÈ ÝÊØÍ ÒÎ ÊÎÄ ÝÊØÍÀ
    inputResult = input.HandleSceneInput_(mx,my);
    if(inputResult.type == SCENE_DIRECTION) {
//        printf("code setted\nnew code %d\n",inputResult.code);
        model.SetCurrentSceneCode(inputResult.code);
    } else if(inputResult.type == ACTION_DIRECTION) {
        //send to action handler
        input.GetActionList()->GetActionByCodeName(inputResult.code)->Click();
        view._InitScenes();
    }
}

void CPresenter::DrawCurrentScene()
{
    view.DrawScene(model.GetCurrentSceneCode());
}

void CPresenter::Quit()
{

}
