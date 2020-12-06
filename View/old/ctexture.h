#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

class CTexture {
public:
    CTexture();
    CTexture(int id,string path) { this->Init(id,path); }
    void Init(int id,string path);

    int GetId() { return id; }
    string Getpath() { return pathToFile; }

private:
    string pathToFile;
    int id;
};

#endif // CTEXTURE_H
