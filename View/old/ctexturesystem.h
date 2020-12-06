#ifndef CTEXTURESYSTEM_H
#define CTEXTURESYSTEM_H

#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include "ctexture.h"

class CTextureSystem {
public:
    CTextureSystem();
    void Init();

    CTexture* GetTexture(int id);

    //
    void CreateTexture(int id,string path);
private:
    vector<CTexture> textureList;

};

#endif // CTEXTURESYSTEM_H
