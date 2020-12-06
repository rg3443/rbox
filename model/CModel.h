#ifndef CMODEL_H_INCLUDED
#define CMODEL_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../pcgGlobal.h"
#include "CGlobalModel.h"
#include "CBaseModelObject.h"
//#include "CLevel/CLevel.h"
//#include "CRuler/CRuler.h"
#include "CPlayer/CPlayer.h"
#include "CWorld/CWorld.h"
#include "../Sup/trand/trand.h"

enum EWorldDirections {
	NORTH,
	SOUTH,
	WEST,
	EAST
};

class CModel : public CBaseModelObject {
public:
    CModel() {}
    void Init(); // first init
    //etaps
	void StartEtap(); // init all data
	void GameplayEtap(); // load level from worldData->location | check_all_objects+travel_status
	void TravelEtap(int eWorldDirection); // if travel status -> de-init current level -> create new level - > gameplayetap
    void ConsoleShow();
    //getters
    bool is_quit() { return gameStatus.quit; }
    CWorld* GetWorld() { return &worldData; }
    SCurrentPlayData GetGameStatus() { return gameStatus; }
    int GetCurrentSceneCode() { return gameStatus.currentSceneCode; }
    CPlayer* GetPlayer() { return &player; }
    //setters
    void SetGameStatus(SCurrentPlayData gameStatus) { this->gameStatus = gameStatus; }
//    CRuler* GetRuler() { return &currentLocationRuler; }

    //methods
    void SetQuit(bool quit) { printf("quit done\n"); gameStatus.quit = quit; }
    void SetCurrentSceneCode(int sceneCode) { gameStatus.currentSceneCode = sceneCode; }
protected:
    CWorld worldData;
//    CRuler currentLocationRuler;
    CPlayer player;
	SCurrentPlayData gameStatus;

	trand randomDevice;
};

#endif // CMODEL_H_INCLUDED
