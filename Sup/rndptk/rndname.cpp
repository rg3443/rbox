#include "rndname.h"

void CRandomNameGenerator::init()
{
	nameList.resize(NAMESIZE);
	nameList[0] = "Jack";
	nameList[1] = "Harold";
	nameList[2] = "Henry";
	nameList[3] = "Stefan";
	nameList[4] = "Herald";
	nameList[5] = "Joseph";
	nameList[6] = "Avgay";
	nameList[7] = "Eros";
	nameList[8] = "Plisfen";
	nameList[9] = "Yerofay";
	nameList[10] = "Plutarchoss";
	nameList[11] = "Avge";
	nameList[12] = "Poy";
	nameList[13] = "Efiv";
	nameList[14] = "Zen";
	nameList[15] = "Zinon";
	nameList[17] = "Zozimos";
	nameList[16] = "Agelay";
	nameList[18] = "Agenor";
	nameList[19] = "Pompiy";
	nameList[20] = "Praxis";
	nameList[21] = "Thomas";
	nameList[22] = "Christopher";
	nameList[23] = "Daniel";
	nameList[24] = "Paul";
	nameList[25] = "Mark";
	nameList[26] = "George";
	nameList[27] = "Kenneth";
	nameList[28] = "Ronald";
	nameList[29] = "Kevin";
	nameList[30] = "Anthony";
	nameList[31] = "Danny";
	nameList[32] = "Timothy";
	nameList[33] = "Frank";
	nameList[34] = "Scott";
	nameList[35] = "Gregory";
	nameList[36] = "Jerry";
	nameList[37] = "Dennis";
	nameList[38] = "Carl";
	nameList[39] = "Gerald";
}

string CRandomNameGenerator::get_name()
{
	int randnum = rand() % NAMESIZE;
	return nameList[randnum];
}
