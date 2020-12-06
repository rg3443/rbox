#include "GSDL2.h"

void SDLGlobal::Init(int scrW,int scrH,int fsize)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    TTF_Init();
    int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
//                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            }
    this->SetScreenSize(scrW,scrH);
    this->SetDefaultFontSize(fsize);
    this->window = SDL_CreateWindow( "sdltest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->SCREEN_W, this->SCREEN_H, SDL_WINDOW_SHOWN );
    this->render = SDL_CreateRenderer( this->GetWindow(), -1, SDL_RENDERER_ACCELERATED );
    eternalRender = &render;
    eternalWindow = &window;
    this->globalDefaultColor.Set(255,0,0);
    this->SetDefaultFont("View/new/misc/fonts/BullpenItalic.ttf");

}

void SDLGlobal::SetDefaultFontSize(int fontSize)
{
    this->defaultFontSize = fontSize;
}

void SDLGlobal::SetScreenSize(int w, int h)
{
    SCREEN_W = w;
    SCREEN_H = h;
}

void SDLGlobal::SetDefaultFont(string ttfFilePath)
{
    if(!(this->defaultFont.isOpen())) {
        this->defaultFont.Open(ttfFilePath.c_str(),this->defaultFontSize);
//        printf("font is open\n");
    } else {
        this->defaultFont.Close();
        this->defaultFont.Open(ttfFilePath,this->defaultFontSize);
    }
}

TTF_Font* SDLGlobal::GetDefaultFont(int fontSize)
{
    this->ReOpenDefaultFont(fontSize);
    return defaultFont.object;
}

void SDLGlobal::ReOpenDefaultFont(int size)
{
    if(defaultFont.isOpen())
        defaultFont.Close();
    defaultFont.Open(defaultFont.filePath,size);
}
