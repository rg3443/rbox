#ifndef CWORLD_H_INCLUDED
#define CWORLD_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "world_ph.h"
#include "../../Sup/trand/trand.h"
#include "../CChunk/CChunkList.h"


class CWorld {
public:
    CWorld() { savesCounter = 0; }
	void Init(trand * randomDevice);
    void _MadeTurn(int turnVal);

	void _CheckLocationTypes();
	void __SaveWorldInfo();
	void personListClanListPostInit_();

    SLocationMap GetLocMap();

    //  GETTERS
    CPersonList* GetPersonList() { return &personList; }
    CClanList* GetClanList() { return &clanList; }
    CBackgroundsList* GEtBackgroundList() { return &backgroundList; }
    CEventList* GetEventList() { return &eventList; }
    CPropertyList* GetPropertyList() { return &propertyList; }
    CChunkList* GetChunkList() { return &chunkList; }

    //  SETTERS


    //  db tables handling || delete this shit from here|place in new class for psql connection
    void _firstCreateTables();
    void _rebuildDbTables();
    void _addLocationData(int turn,cords locationPos,int personAmmount,SConsequences * currentConseq);
    void _dropLocationData();
    void _addEventData(int turn,cords pos, string name);
    void _dropEventData();
    void _addPropertyData(int turn,int id,int globalPosX, int globalPosY, cords leftUperTile,cords rightDownTile,int personOwnerId/*, int type*/); //todo:
    void _rebuildPropertyData(int turnVal);
    void _dropPropertyData();

private:
    void _InitLocations(); // init locations with chunkList

protected:
    vector< vector<CLocation> > locations;
	CPersonList personList;
	CClanList clanList;
	CBackgroundsList backgroundList;
	CEventList eventList;
    CPropertyList propertyList;
    CEventRandomiser eventRandomiser;
	CTurnChecker turnChecker;
	CChunkList chunkList;

    int savesCounter;
    trand * randomDevice;


};

#endif
