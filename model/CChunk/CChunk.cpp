#include "CChunk.h"
//todo: класс путсоват мне кажется чето еще может делать
void CChunk::Init(int id,int locationType)
{
    this->id = id;
    this->locationType = locationType;
    textureCodeField.resize(CHUNK_SIZE);
    for(int y=0;y<CHUNK_SIZE;y++) {
        textureCodeField[y].resize(CHUNK_SIZE);
        for(int x=0;x<CHUNK_SIZE;x++) {
            textureCodeField[y].resize(CHUNK_SIZE);
        }
    }
}

void CChunk::SetTileTypes(int data[CHUNK_SIZE][CHUNK_SIZE])
{
    for(int y=0;y<CHUNK_SIZE;y++) {
        for(int x=0;x<CHUNK_SIZE;x++) {
                textureCodeField[y][x] = data[y][x];
        }
    }
}
