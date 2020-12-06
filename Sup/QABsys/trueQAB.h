#ifndef TRUEQAB_H_INCLUDED
#define TRUEQAB_H_INCLUDED
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "../../pcgGlobal.h"
#include "../Logs/ScreenSaver/CScreenSaver.h"

//#include "../../Model/Player.h"

class CMenu_sys;
class CObjectList;
class CWorld;
class CModel;

const int WINDOW_RESIZE_VALUE = 30;

class QAB {
public:
    QAB() {  }
    void setup( );

    void insert_ms(CMenu_sys * ms) { this->ms = ms; }
    void insert_objlist(CObjectList* objlist) { this->objlist = objlist; }
    void insert_world(CWorld* world) { this->world = world; }
    void insert_model(CModel* model) { this->model = model; }
    void set_quit(bool quit) { this->quit = quit; }
    void set_screen(cords size) { SCREEN_W = size.x; SCREEN_H = size.y;  }
    void set_gameplay(bool stat) { gameplay = stat; }
    void set_plrpos(cords pos) { plrpos = pos; }

    CWorld * get_wrd() { return world; }
    CMenu_sys * get_ms() { return ms; }
    CObjectList * get_objlist() { return objlist; }
    CModel * get_model() { return model; }
    bool* is_gameplay() { return &gameplay; }
    bool* is_quit() { return &quit; }
    int get_scw() { return SCREEN_W; }
    int get_sch() { return SCREEN_H; }


    int* get_gid() { return &global_object_id_counter; }
    cords* get_plrpos() { return &plrpos; }

protected:
    CMenu_sys * ms;
    CObjectList * objlist;
    CModel* model;
    CWorld* world;

    bool quit;
    bool gameplay;
    cords plrpos;
    int global_object_id_counter;

    //  SCREEN SIZE DATA
    //float mashx,mashy; // IN %%%
    int SCREEN_W,SCREEN_H;
    int etSCREEN_W, etSCREEN_H;
    CScreenSaver save_screen;
};

#endif // TRUEQAB_H_INCLUDED
