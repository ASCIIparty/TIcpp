#ifndef TICPP_BUECHEREI_TLIBRARY_H
#define TICPP_BUECHEREI_TLIBRARY_H


#include "TMedium.h"
#include "TPerson.h"

class TLibrary {
    string Name;
    TAddress Address;
    TPerson *Manager;
    TMedium *MediumList[];
};


#endif //TICPP_BUECHEREI_TLIBRARY_H
