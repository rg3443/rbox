#ifndef CLOCATION_H_INCLUDED
#define CLOCATION_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "CPerson.h"
//#include "../CLevel/CMap/CTile.h"
#include "../CPlayerPhase/Field/CMetaTile.h"
#include "GWorld.h"
#include "../CChunk/CChunk.h"
#include "../CChunk/CChunkList.h"



enum ELocationTypes {
    WILDS,
    VILLAGE,
    CITY,
    UNIVERSAL //FOR CHUNK RANDOMISE
};

class CLocation {
public:
	CLocation() {}
	void Init(int x_,int y_,int type);

	//	GETTERS
	int GetW() { return w; }
    int GetH() { return h; }
    int GetX() { return x; }
	int GetY() { return y; }
	int GetPersonAmmount() { return persona.size(); }
	int GetLocationType() { return locationType; }
	int GetWildEnemyAmmount() { return wildEnemyAmmount; }
    int GetPropertyAmmount() { return avablePropertyList.size(); }
	CTile* GetTile(int tileX, int tileY) { return &tileField[tileY][tileX]; } //теперь хз где мля это хранить, придется возвращать| сделал новую структуру
    CPerson* GetPerson(int personId) { return persona[personId]; }
    SLocationStatus* GetLocationStatus( ) { return &locationStatus; }
    SConsequences* GetLocationSituation( ) { return &locationSituation; }
    vector<CPerson*> GetAllPersons( ) { return persona; }
    vector<int> GetActorsId( ) { return actingPersonList; }
    SProperty* GetProperty(int id) { return &avablePropertyList[id]; }
    SProperty* GetRandomFreeProperty();
	//	SETTERS
	void SetWH(int w,int h) { this->w=w; this->h=h; }
	void SetXY(int x,int y) { this->x=x; this->y=y; }
    void SetType(int locationType);
    void SetLocationSituation(SConsequences newSit) { locationSituation = newSit; }
    void SetTiles(CChunk * chunk,int cx,int cy);

	//	METHODS
	void AddPerson(CPerson* newPerson);
	void ErasePerson(int personId);
	void ErasePerson(string personName);
    void ErasePerson(CPerson* personToErase);
	void ErasePersonByGlobalId(int globalId);
    void AddActingPersonId(int id) { actingPersonList.push_back(id); }
    void ClearActingPersonIdList() { actingPersonList.resize(0); }
    void RecalculateSituation();
    void ChangeWildEnemyAmmount(int value) { wildEnemyAmmount += value; }
    void _console_show( );
    void _console_show(int countSave);
    CChunk GetChunk(int chunkIdX,int chunkIdY); //not tile pos

protected:
	int x,y,w,h,locationType;
	//todo: хули оно не видется
	vector< vector<CTile> > tileField;
	vector<CPerson*> persona;
    vector<int> actingPersonList;
	SLocationStatus locationStatus;
	SConsequences locationSituation;

    vector<SProperty> avablePropertyList;//??? avable ???

	int wildEnemyAmmount;
};

struct SLocationMap {
    vector< vector<CLocation*> > locations;
    SLocationMap() {}
    SLocationMap(vector<vector<CLocation*>> locs) {
        locations = locs;
    }
};

#endif
