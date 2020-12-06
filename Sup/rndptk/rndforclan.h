#ifndef RNDFORCLAN_H_INCLUDED
#define RNDFORCLAN_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "rndptk.h"

class CRandomClanGenerator {
public:
	CRandomClanGenerator(){}
	void init();
	string get_clan_name();
	int get_clan_type();

protected:
	Potok rndValForType;
	vector<string> clanNameList;
};

#endif
