#ifndef CCHUNK_H_INCLUDED
#define CCHUNK_H_INCLUDED\

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int CHUNK_SIZE = 10;

class CChunk {
public:
    CChunk() {}
    CChunk(int id,int locationType) { this->Init(id,locationType); }
    void Init(int id,int locationType);
    //leverage
    void RandomiseTiles();
    //setters
    void SetTextureCode(int code,int x,int y) { textureCodeField[y][x] = code; }
    void SetTileTypes(int data[CHUNK_SIZE][CHUNK_SIZE]);
    void SetName(string name) { this->name = name; }
    //getters
    int GetId() { return id; }
    int GetTextureCode(int x,int y) { return textureCodeField[y][x]; }
    int GetLocationType() { return locationType; }
    string GetName() { return name; }


protected:
    string name;                            //optional
    int id,                                 // 0 - ...
    locationType;                           // ELocationTypes
    vector<vector<int>> textureCodeField;   // ETextureCodeName

};



#endif // CCHUNK_H_INCLUDED
