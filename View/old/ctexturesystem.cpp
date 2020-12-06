#include "ctexturesystem.h"

CTextureSystem::CTextureSystem()
{

}

void CTextureSystem::Init()
{
    this->CreateTexture(0,"misc\\icons\\map\\tgrass2.bmp");
}

CTexture* CTextureSystem::GetTexture(int id)
{
    for(int i=0;i<textureList.size();i++)
    {
        if(textureList[i].GetId() == id) {
            return &textureList[i];
        }
    }
}

void CTextureSystem::CreateTexture(int id, string path)
{
    textureList.push_back(CTexture(id,path));
}
