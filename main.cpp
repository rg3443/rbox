#include <stdio.h>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <string.h>

#include "Presenter/cpresenter.h"

#include "View/new/CBRender/CBRender.h"
#include "View/new/GSDL2.h"
#include "model/CWorld/CWorld.h"
//#include "Sup/boost/random.hpp"
#include "Sup/trand/trand.h"


int main( int argc, char* args[] )
{
    #if 0
    setlocale(LC_ALL,"Russian");
    CPresenter prog;
    prog.Init();
    prog.TestRun();
    #endif
    CWorld wrld; wrld.Init(new trand);
    //trand rtool;
    //rtool.UpdateSeed();
    //CWorld wrld;
    //wrld.Init(&rtool);
}
