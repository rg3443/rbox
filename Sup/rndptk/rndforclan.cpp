#include "rndforclan.h"

void CRandomClanGenerator::init()
{
	clanNameList.resize(1);
	clanNameList[0] = "Ubuntu";
	
	//rndValForType.setup(98,0,4);
	//rndValForType.shuffle();
}

string CRandomClanGenerator::get_clan_name()
{
	int randomvalue = 0;
	return clanNameList[randomvalue];
}

int CRandomClanGenerator::get_clan_type() 
{
	return rand() % 4;
}
