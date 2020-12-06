#include "CModel.h"

void CModel::Init()
{
	randomDevice.UpdateSeed();//it is init
	player.Init( );
	worldData.Init( &randomDevice );
	printf("world init done\n");
	//currentLocationRuler.Init(&player);
	gameStatus.quit = false;
	gameStatus.currentSceneCode = TEST_SCENE;
}

void CModel::StartEtap()
{
    gameStatus.currentLocationPos.setcord(30,30);
    //todo: 20.04.20 was change this world method
    //currentLocationRuler.InitLevel(worldData.GetLocMap()->GetLocation(gameStatus.currentLocationPos.x,gameStatus.currentLocationPos.y));
}

void CModel::GameplayEtap()
{

}

void CModel::TravelEtap(int eWorldDirection)
{
	switch(eWorldDirection)
	{
	case NORTH:
		gameStatus.TravelNorth();
	break;
	case SOUTH:
		gameStatus.TravelSouth();
	break;
	case WEST:
		gameStatus.TravelWest();
	break;
	case EAST:
		gameStatus.TravelEast();
	break;
	}
}
