#ifndef RNDSNAME_H_INCLUDED
#define RNDSNAME_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctime>
using namespace std;

class CRandomSNameGenerator {
public:
	CRandomSNameGenerator() { SECONDNAMESIZE = 40; }
	void init();
	string get_sname();
	int size() { return SECONDNAMESIZE; }
protected:
	int SECONDNAMESIZE;
	vector<string> snameList;
};

#endif
