#ifndef GSDL2_H_INCLUDED
#define GSDL2_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#include <SDL.h>
#include <SDL_ttf.h>
#include "scenes/GSceneComponents.h"


class SDLGlobal {
public:
    SDLGlobal() {}
    void Init(int scrW,int scrH,int fsize);

    //getters
    int GetScreenW() { return SCREEN_W; }
    int GetScreenH() { return SCREEN_H; }
    int GetDefaultFontSize() { return defaultFontSize; }
    TTF_Font* GetDefaultFont() { return defaultFont.object; }
    TTF_Font* GetDefaultFont(int fontSize);
    SDL_Renderer* GetRender() { return render; }
    SDL_Window* GetWindow() { return window; }
    SRGB GetDefaultColor() { return globalDefaultColor; }

    //setters
    void SetScreenSize(int w,int h);
    void SetDefaultFontSize(int fontSize);
    void SetDefaultColor(SRGB color);
    void SetDefaultFont(string ttfFilePath);

    //leverage
    void ReOpenDefaultFont(int size);

protected:
    int SCREEN_W,SCREEN_H;
    int defaultFontSize;
    SRGB globalDefaultColor;

    SDL_Renderer* render;
    SDL_Window* window;
    SDL_Renderer** eternalRender;
    SDL_Window** eternalWindow;
    SFont defaultFont;

};

#endif // GSDL2_H_INCLUDED
