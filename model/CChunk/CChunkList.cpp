#include "CChunkList.h"

void CChunkList::Init()
{
    CChunk newChunk(0,UNIVERSAL);
    newChunk.SetName("plane");
   int data[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
    };
    newChunk.SetTileTypes(data);
    chunkList.push_back(newChunk);
}

CChunk* CChunkList::RandomiseChunk(int locationType)
{
    vector<CChunk*> relevantChunks;
    for(int i=0;i<chunkList.size();i++) {
        if(chunkList[i].GetLocationType() == locationType || chunkList[i].GetLocationType() == UNIVERSAL) {
            relevantChunks.push_back(&chunkList[i]);
        }
    }
    int choosenChunkId = rand() % relevantChunks.size();
    try {
        if(choosenChunkId >= relevantChunks.size()) {
            throw "ERROR:(12141) \n";
        }
        return relevantChunks[choosenChunkId];
    }
    catch(const char* err) { printf(err); }
}
