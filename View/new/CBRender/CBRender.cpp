#include "CBRender.h"
//#include "SDL/SDL_ttf.h"

void CBRender::Init(SDLGlobal * sdlGlobal)
{
    this->sdlGlobal = sdlGlobal;
    this->render = sdlGlobal->GetRender();
    this->window = sdlGlobal->GetWindow();
    this->gfc = sdlGlobal->GetDefaultColor();

}

void CBRender::DrawText(SText txt)
{
    TTF_Font* Sans = sdlGlobal->GetDefaultFont(txt.fontSize);

    SDL_Color White;
    if(txt.isDefaultColor())
        White = sdlGlobal->GetDefaultColor().GetSDLColor();  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
    else
        White = txt.color.GetSDLColor();

    SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans, txt.text.c_str(), txt.color.GetSDLColor()); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture* Message = SDL_CreateTextureFromSurface(this->render, surfaceMessage); //now you can convert it into a texture

    SDL_Rect Message_rect = txt.GetSDLRect(); //create a rect
    Message_rect.x = txt.textField.ulPoint.x;
    Message_rect.y = txt.textField.ulPoint.y;
    Message_rect.w = txt.textField.drPoint.x - txt.textField.ulPoint.x;
    Message_rect.h = txt.textField.drPoint.y - txt.textField.ulPoint.y;
    //PrintSSquare(txt.textField);
    //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understand

    //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

    SDL_RenderCopy(this->render, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

    //Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void CBRender::DrawLine(SLine ln)
{
    SDL_SetRenderDrawColor(render,ln.color.r,ln.color.g,ln.color.b,255);
    SDL_RenderDrawLine(render,ln.p1.x,ln.p1.y,ln.p2.x,ln.p2.y);
    SDL_SetRenderDrawColor(render,this->gfc.r,this->gfc.g,this->gfc.b,255);
}

void CBRender::DrawSquare(SSquare sq)
{
    SPoint p1,p2,p3,p4;
    p1.x = sq.ulPoint.x;
    p1.y = sq.ulPoint.y;
    p2.x = sq.drPoint.x;
    p2.y = sq.ulPoint.y;
    p3.x = sq.drPoint.x;
    p3.y = sq.drPoint.y;
    p4.x = sq.ulPoint.x;
    p4.y = sq.drPoint.y;

    if(sq.type == FILLED) {
        SDL_Rect rect = {p1.x,p1.y,p3.x-p1.x,p3.y-p1.y};
        SDL_SetRenderDrawColor(render,sq.inlineColor.r,sq.inlineColor.g,sq.inlineColor.b,255);
        SDL_RenderFillRect(render,&rect);
        SDL_SetRenderDrawColor(render,this->gfc.r,this->gfc.g,this->gfc.b,255);
    }

    this->DrawLine(SLine(p1,p2,sq.outlineColor));
    this->DrawLine(SLine(p2,p3,sq.outlineColor));
    this->DrawLine(SLine(p3,p4,sq.outlineColor));
    this->DrawLine(SLine(p4,p1,sq.outlineColor));
    //printf("sqr done\n");
}

void CBRender::DrawButton(SButton bt)
{
    this->DrawSquare(bt.sqrFld);
    this->DrawText(bt.text);
}

void CBRender::DrawTableBox(STableBox tbx)
{
    for(int column=0;column<tbx.tileMatrix[column].size();column++) {
        for(int row=0;row<tbx.tileMatrix.size();row++)
        {
            this->DrawSquare(tbx.tileMatrix[row][column].textField);
            //this->DrawText( tbx.GetData( column , row ) );
        }
    }
}

void CBRender::DrawTableButtonBox(STableButtonBox tbbx)
{
    for(int colnamid=0;colnamid<tbbx.columnNames.size();colnamid++) {
        this->DrawText( tbbx.columnNames[colnamid] );
    }
    for(int column=0;column<tbbx.buttonMatrix[column].size();column++) {
        for(int row=0;row<tbbx.buttonMatrix.size();row++)
        {
            this->DrawButton(tbbx.buttonMatrix[row][column]);
            //SText txt = tbbx.GetButtonText(row,column);
            //this->DrawText( txt );
        }
    }
}

void CBRender::DrawTexture(STexture txtr)
{
    this->DrawSquare(txtr.imgField);
    SDL_Rect rct = txtr.GetSDLRect();
    SDL_RenderCopy(this->render,txtr.object,NULL,&rct);
}

void CBRender::DrawDialogBlock(SDialogBlock dbk)
{

}

