#include "CView.h"

void CView::Init(CModel * model,CActionList * actionList)
{
    this->model = model;
    this->actionList = actionList;
    sdlGlobal.Init(800,500,16);
    render.Init(&sdlGlobal);
    this->_InitScenes();
}

void CView::DrawScene(int sceneCode)
{
    SDL_SetRenderDrawColor(render.GetRender(),0,0,0,255);
    SDL_RenderClear(render.GetRender());

    for(int scenid=0;scenid<sceneList.size();scenid++) {
        if(sceneList[scenid].GetCode() == sceneCode) {
            CBaseScene currentScene = sceneList[scenid];
            //LINES
            if(currentScene.GetLineSize() != 0)
            for(int linid=0;linid<currentScene.GetLineSize();linid++) {
                render.DrawLine(currentScene.GetLine(linid));
            }

            //TEXT
            if(currentScene.GetTextSize() != 0)
            for(int textid=0;textid<currentScene.GetTextSize();textid++) {
                render.DrawText(currentScene.GetText(textid));
            }

            //SQUARES
            if(currentScene.GetSquareSize() != 0)
            for(int squarid=0;squarid<currentScene.GetSquareSize();squarid++) {
                render.DrawSquare(currentScene.GetSquare(squarid));
            }

            //BUTTONS
            if(currentScene.GetButtonSize() != 0)
            for(int buttid=0;buttid<currentScene.GetButtonSize();buttid++) {
                SButton bt = currentScene.GetButton(buttid);
                render.DrawButton(bt);
//                printf("button sqr: x1=%d|y1=%d|x2=%d|y2=%d\n",bt.sqrFld.ulPoint.x,bt.sqrFld.ulPoint.y,bt.sqrFld.drPoint.x,bt.sqrFld.drPoint.y);
//                printf("button id%d was drawed\n",buttid);
            }
//            printf("ssss");
            //TABLES
            //if(currentScene.GetTableBoxSize() != 0)
            //for(int tablid=0;tablid<currentScene.GetTableBoxSize();tablid++) {
            //    render.DrawTableBox(currentScene.GetTableBox(tablid));
            //}
            if(currentScene.GetTableButtonBoxSize() != 0)
            for(int tbbxid=0;tbbxid<currentScene.GetTableButtonBoxSize();tbbxid++) {
                //currentScene.GetTableButtonBox(tbbxid).PrintData();
                render.DrawTableButtonBox(currentScene.GetTableButtonBox(tbbxid));
            }
            if(currentScene.GetTextureSize() != 0)
            for(int txtrid=0;txtrid<currentScene.GetTextureSize();txtrid++) {
                render.DrawTexture(currentScene.GetTexture(txtrid));
            }

        }
    }

    //todo: SDELAT ADEKVATNUU SYSTEM COMPONENTOFF BEZ TABLE'OFF BECOUSE TABLES BUDUT KAK TIP SCENE, OK?
    // A TAK KAK OBSHIY SPISOK U VSEH SCENE TO SPISOK DOLJEN HRANIT POINTER NOT JUST OBJECT
    SDL_RenderPresent(render.GetRender());
}

void CView::_InitScenes()
{
    sceneList.resize(0);
    this->_InitMainScene();
        this->_printSceneAfterInit();
    this->_InitTestScene();
        this->_printSceneAfterInit();
    this->_InitPersosShowScene();
        this->_printSceneAfterInit();
    this->_InitSettingsScene();
        this->_printSceneAfterInit();
    this->_InitGameScene();
        this->_printSceneAfterInit();
}

void CView::_InitMainScene()
{
    CBaseScene scn;
    scn.SetCode(MAIN_SCENE);
    scn.SetDescription("some MENU main shiet menu as fuck\n");

    STableButtonBox tbbx(SPoint((sdlGlobal.GetScreenW()/2)-60,60),1,4,120,40);
    tbbx.SetButtonText(SText("NEW GAME",32,SRGB(255,0,0)),0,0);
    tbbx.SetButtonText(SText("LOAD GAME",32,SRGB(255,0,0)),1,0);
    tbbx.SetButtonText(SText("SETTINGS",32,SRGB(255,0,0)),2,0);
    tbbx.SetButtonText(SText("QUIT",32,SRGB(255,0,0)),3,0);
    scn.AddTableButtonBox(tbbx);

    sceneList.push_back(scn);
}

void CView::_InitTestScene()
{
    CBaseScene scn;
    scn.SetCode(TEST_SCENE);
    scn.SetDescription("some easy shiet test menu as fuck\n");

    SText txt("eta huita rabotaet",16,SRGB(16,144,144),SSquare(
                                            SPoint(20,20),SPoint(400,400),
                                            OUTLINED,
                                            SRGB(255,0,0),SRGB(0,0,0)
                                           ));
    scn.AddText(txt);


    STableButtonBox tbx = STableButtonBox(
                                          SPoint(30,30),5,5,25,25
                                         );
    for(int row=0;row<tbx.buttonMatrix.size();row++) {
        for(int column=0;column<tbx.buttonMatrix[row].size();column++) {
            tbx.SetButtonText(SText("testt",16,SRGB(255,0,0)),row,column);
        }
    }
    scn.AddTableButtonBox(tbx);

//    printf("SUKKKKKA\n");
    SSquare buttonSquare = SSquare(
                                   SPoint(0,0),
                                   SPoint(100,100),
                                   OUTLINED,
                                   SRGB(255,0,0),
                                   SRGB(255,0,0)
                                   );
    scn.AddButton(SButton(
                           buttonSquare,
                           SCENE_DIRECTION,
                           SText(
                                 "text",
                                 16,
                                 SRGB(255,0,0),
                                 buttonSquare
                                 ),
                           MAIN_SCENE
                           ));
    sceneList.push_back(scn);
}

void CView::_InitPersosShowScene()
{
    CBaseScene scn;
    scn.SetCode(PERSONSHOW_SCENE);
    scn.SetDescription("some PERSONSHOW shiet menu as fuck\n");
    //vector<vector<SText>>

    //ACTIONS ALLWAYS FIRST
    actionList->AddAction(CAction(PAGEDOWN_ACTION,0,DICREMENT));
    actionList->AddAction(CAction(PAGEUP_ACTION,0,INCREMENT));
    //actionList->GetActionByCodeName(PAGEDOWN)->SetTwinAction(actionList->GetActionByCodeName(PAGEUP));
//    printf("persos show scene doen 80%\n");
    //CPerson* person = model->GetWorld()->GetPersonList()->get_person(0);
    SText randomPersonName("lets try very long text, what we will have? good question, but without reson i would not recomend to ask things like this.",32,SRGB(255,0,0),SSquare(
                                                                       SPoint(0,0),
                                                                       SPoint(sdlGlobal.GetScreenW(),sdlGlobal.GetScreenH()),
                                                                       OUTLINED,
                                                                       SRGB(255,0,0),
                                                                       SRGB(255,0,0)
                                                                       ));

    STableButtonBox tbbx(SPoint(100,0),7,10,80,30);
    tbbx.SetColumnName(0,"id"); tbbx.SetColumnW(30,0);
    tbbx.SetColumnName(1,"fist name"); tbbx.SetColumnW(80,1);
    tbbx.SetColumnName(2,"sex name"); tbbx.SetColumnW(80,2);
    tbbx.SetColumnName(3,"proffesion"); tbbx.SetColumnW(80,3);
    tbbx.SetColumnName(4,"X POS"); tbbx.SetColumnW(30,4);
    tbbx.SetColumnName(5,"Y POS"); tbbx.SetColumnW(30,5);
    tbbx.SetColumnName(6,"money"); tbbx.SetColumnW(30,6);
    int personId = 0;
    int idModifire = actionList->GetActionByCodeName(PAGEDOWN_ACTION)->GetHandledValue()+actionList->GetActionByCodeName(PAGEUP_ACTION)->GetHandledValue(); // for scrolling feature
    for(int row=0;row<10;row++) {
        CPerson* person = model->GetWorld()->GetPersonList()->get_person(personId+row+idModifire);
        tbbx.SetButtonText(SText(to_string(person->GetId()),32,SRGB(128,128,0)),row,0);
        tbbx.SetButtonText(SText(person->GetFname(),16,SRGB(128,128,0)),row,1);
        tbbx.SetButtonText(SText(person->GetSname(),16,SRGB(128,128,0)),row,2);
        tbbx.SetButtonText(SText(person->GetBackground()->get_name(),16,SRGB(128,128,0)),row,3);
        tbbx.SetButtonText(SText(to_string(person->GetCurrLocX()),16,SRGB(128,128,0)),row,4);
        tbbx.SetButtonText(SText(to_string(person->GetCurrLocY()),16,SRGB(128,128,0)),row,5);
        tbbx.SetButtonText(SText(to_string(person->GetMoney()),16,SRGB(128,128,0)),row,6);
    }

    scn.AddTableButtonBox( tbbx );




    STexture testTexture(T_GAMBLECUBE,"misc/icons/gui/cubes.png",SSquare(
                                                            SPoint(0,51),SPoint(100,150),
                                                            OUTLINED,
                                                            SRGB(255,0,0),SRGB(255,0,0)
                                                            ));
    testTexture.CreateTexture(sdlGlobal.GetRender());
    scn.AddTexture(testTexture);


















//
    SSquare pagedownSqr(
                        SPoint(0,0),SPoint(50,50),
                        OUTLINED,
                        SRGB(255,0,0),
                        SRGB(255,0,0)
                        );
    SButton pageDown(pagedownSqr,ACTION_DIRECTION,SText("<",16,SRGB(255,0,0),pagedownSqr),PAGEDOWN_ACTION);
    scn.AddButton(pageDown);

    SSquare pageupSqr(
                      SPoint(50,0),SPoint(100,50),
                      OUTLINED,
                      SRGB(255,0,0),
                      SRGB(255,0,0)
                      );
    SButton pageUp(pageupSqr,ACTION_DIRECTION,SText(">",16,SRGB(255,0,0),pageupSqr),PAGEUP_ACTION);
    scn.AddButton(pageUp);

    SSquare goToMainSqr(
                        SPoint(0,151),SPoint(100,250),
                        OUTLINED,
                        SRGB(255,0,0),SRGB(250,0,0)
                        );
    SButton goToMain(goToMainSqr,SCENE_DIRECTION,SText("MAIN MENU",16,SRGB(255,0,0),goToMainSqr),MAIN_SCENE);
    scn.AddButton(goToMain);

    sceneList.push_back(scn);
}

void CView::_InitGameScene()
{
    CBaseScene scn;
    //SCENE SETUP
    scn.SetCode(GAME_SCENE);
    scn.SetDescription("actual game, there must be tiles render");

    // ACTIONS PRE-INIT
    actionList->AddAction(CAction(MOVEUP_ACTION,0,DICREMENT));     //--Y
    actionList->AddAction(CAction(MOVEDOWN_ACTION,0,INCREMENT));   //++Y
    actionList->AddAction(CAction(MOVELEFT_ACTION,0,DICREMENT));   //--X
    actionList->AddAction(CAction(MOVERIGHT_ACTION,0,INCREMENT));   //++X

    //  TILE TEXTURES SETUP + INGAME STUFF INIT
    CPlayer* player = model->GetPlayer();
    SLocationMap worldMap = model->GetWorld()->GetLocMap();
    CLocation* currentLocation = worldMap.locations[player->GetPerson()->GetCurrLocY()][player->GetPerson()->GetCurrLocX()];

    //todo: first
    SPoint tilePos(0,0);
    int tileSize = 50;
    vector<vector<STexture>> tileMtrx;
    tileMtrx.resize(currentLocation->GetH());
    for(int y=0;y<tileMtrx.size();y++) {
        tileMtrx[y].resize(currentLocation->GetW());
        tilePos.x = 0;
        for(int x=0;x<tileMtrx[y].size();x++) {
            CTile* currentTile = currentLocation->GetTile(x,y);
            SSquare tileSqr(
                            tilePos,SPoint((tilePos.x+tileSize),(tilePos.y+tileSize)),
                            OUTLINED,
                            SRGB(0,100,0),SRGB(0,0,0)
                            );
            //  FIRST_LAYER
            switch(currentTile->GetTextureCode())
            {
            case T_STONE_TILE:
                tileMtrx[y][x].Init(T_STONE_TILE,"misc/icons/map/tgrass1.png",tileSqr);
            break;
            case T_FOREST_TILE:
                tileMtrx[y][x].Init(T_FOREST_TILE,"misc/icons/map/tgrass1.png",tileSqr);
            break;
            case T_WATER_TILE:
                tileMtrx[y][x].Init(T_WATER_TILE,"misc/icons/map/tgrass1.png",tileSqr);
            break;
            }
            //  SECOND_LAYER
            switch(currentTile->GetObjectCode())
            {
            case 0:
            break;
            }
            //  PERSON_LAYER
            tilePos.x+=tileSize;
            scn.AddTexture(tileMtrx[y][x]);
        }
        tilePos.y+=tileSize;
    }
    //  BUTTONS
    SSquare pauseSqr(
                     SPoint(0,0),SPoint(30,30),
                     OUTLINED,
                     SRGB(255,0,0),SRGB(255,0,0)
                     );
    SButton pauseButton(pauseSqr,SCENE_DIRECTION,SText("||",16,SRGB(255,0,0),pauseSqr),PAUSE_SCENE);

    SSquare moveupSqr(
                      SPoint(30,0),SPoint(sdlGlobal.GetScreenW(),sdlGlobal.GetScreenH()/2),
                      INVISIBLE,
                      SRGB(0,0,0),SRGB(0,0,0)
                      );
    SButton moveupButton(moveupSqr,ACTION_DIRECTION,SText("",16,SRGB(0,0,0),moveupSqr),MOVEUP_ACTION);


    sceneList.push_back(scn);
}

void CView::_InitSettingsScene()
{
    CBaseScene scn;
    //SCENE SETUP
    scn.SetCode(SETTINGS_SCENE);
    scn.SetDescription("Settings, volume, font size etc.");



    sceneList.push_back(scn);
}

CBaseScene* CView::GetSceneByCode(int sceneCode)
{
    for(int i=0;i<sceneList.size();i++) {
        if(sceneList[i].GetCode() == sceneCode) {
//                printf("scene with decription choosen: %s|id=%d\n", sceneList[i].GetDescription(),sceneList[i].GetCode());
                return &sceneList[i];
        }
    }
//    printf("scene was not fount\n");
}

void CView::_printSceneAfterInit()
{
    printf("scene was inited|description - %s\n",sceneList[sceneList.size()-1].GetDescription());
}





