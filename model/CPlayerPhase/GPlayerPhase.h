#ifndef GPLAYERPHASE_H_INCLUDED
#define GPLAYERPHASE_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;

//PAWNAI STUFF
enum EAITypes {
    PANIC,
    AGGRESIVE,
    DEFFENDING,
    NEUTRAL,
    COMRAD
};

struct SStartedInteraction {
    bool existed;
    int interactionCode;
};

struct SDecision {
    bool is_attacking,is_blocking,is_parrying;
    int directionCode;
    SStartedInteraction interaction;
    SDecision() {}
    SDecision(int directCode, SStartedInteraction interact, bool is_attacking_,bool is_blocking_,bool is_parrying_) {
        directionCode = directCode;
        interaction = interact;
        is_attacking = is_attacking_;
        is_blocking = is_blocking_;
        is_parrying = is_parrying_;
    }

};

#endif // GPLAYERPHASE_H_INCLUDED
