#ifndef CCHUNKLIST_H_INCLUDED
#define CCHUNKLIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "CChunk.h"
#include "../CWorld/CLocation.h"

class CChunkList {
public:
    CChunkList() {}
    void Init();
    //setters
    //getters
    CChunk* GetChunk(int id) { return &chunkList[id]; }
    CChunk* RandomiseChunk(int locationType);
protected:
    vector<CChunk> chunkList;
};

#endif // CCHUNKLIST_H_INCLUDED
