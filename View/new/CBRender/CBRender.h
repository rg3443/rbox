#ifndef CBRENDER_H_INCLUDED
#define CBRENDER_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;
//#include <SDL2/SDL.h>
#include "../GSDL2.h"

class CBRender {
public:
    CBRender() {}
    void Init(SDLGlobal * sdlGlobal);

    //methods
    void DrawLine(SLine ln);
    void DrawSquare(SSquare sq);
    void DrawText(SText txt);
    void DrawButton(SButton bt);
    void DrawTableBox(STableBox tbx);
    void DrawTableButtonBox(STableButtonBox tbbx);
    void DrawTexture(STexture txtr);
    void DrawDialogBlock(SDialogBlock dbk);

    //getters
    SDL_Renderer* GetRender() { return render; }
    SDL_Window* GetWindow() { return window; }

protected:
    SDLGlobal * sdlGlobal;

    SRGB gfc;// globalDefaultColor;

    SDL_Renderer* render;
    SDL_Window* window;
};

#endif // CBRENDER_H_INCLUDED
