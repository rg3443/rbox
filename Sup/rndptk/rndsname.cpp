#include "rndsname.h"

void CRandomSNameGenerator::init()
{
	snameList.resize(SECONDNAMESIZE);
	snameList[0] = "Herer";
	snameList[1] = "Raspus";
	snameList[2] = "Stafford";
	snameList[3] = "Lukachoff";
	snameList[4] = "Bugachoff";
	snameList[5] = "Lihachoff";
	snameList[6] = "Mudachoff";
	snameList[7] = "Verner";
	snameList[8] = "Adams";
	snameList[9] = "Aldridge";
	snameList[10] = "Baker";
	snameList[11] = "Barber";
	snameList[12] = "Barlow";
	snameList[13] = "Barrett";
	snameList[14] = "Bee";
	snameList[15] = "Bennett";
	snameList[16] = "Brooks";
	snameList[17] = "Brown";
	snameList[18] = "Bruce";
	snameList[19] = "Carter";
	snameList[20] = "Carson";
	snameList[21] = "Cooper";
	snameList[22] = "Crystal";
	snameList[23] = "Dean";
	snameList[24] = "Evans";
	snameList[25] = "Ford";
	snameList[26] = "Franklin";
	snameList[27] = "Green";
	snameList[28] = "Hart";
	snameList[29] = "Harris";
	snameList[30] = "Hicks";
	snameList[31] = "Howard";
	snameList[32] = "Johnson";
	snameList[33] = "Hunt";
	snameList[34] = "Jones";
	snameList[35] = "Jordan";
	snameList[36] = "Kimberly";
	snameList[37] = "Little";
	snameList[38] = "Meredith";
	snameList[39] = "Morgan";
}

string CRandomSNameGenerator::get_sname()
{
	int randomvalue = rand() % SECONDNAMESIZE;
	return snameList[randomvalue];
}
