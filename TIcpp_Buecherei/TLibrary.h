#ifndef TICPP_BUECHEREI_TLIBRARY_H
#define TICPP_BUECHEREI_TLIBRARY_H


#include "TMedium.h"
#include "TPerson.h"

class TLibrary {
    string name;
    TAddress address;
    TPerson *manager;
    static vector<TMedium> *mediumList;

    TLibrary(string n, TAddress a, TPerson *m, vector<TMedium> *mL);
    ~TLibrary();

    string getName();
    void print();
    static vector<TMedium> getMediumList();
    void add(TMedium medium);
};


#endif //TICPP_BUECHEREI_TLIBRARY_H
