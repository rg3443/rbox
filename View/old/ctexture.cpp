#include "ctexture.h"

CTexture::CTexture()
{

}

void CTexture::Init(int id, string path)
{
    this->id = id;
    pathToFile = path;
}
