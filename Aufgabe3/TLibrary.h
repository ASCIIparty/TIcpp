
#ifndef TICPP_BUECHEREI_TLIBRARY_H
#define TICPP_BUECHEREI_TLIBRARY_H

#include <vector>
#include "TMedium.h"
#include "TPerson.h"


class TLibrary {
    string name;
    TAddress address;
    TPerson *manager;
    vector<TMedium> *mediumList;
    public:
    TLibrary(string n, TAddress a, TPerson *m);
    ~TLibrary();

    string getName();
    void print();
    vector<TMedium> * getMediumList();
    void add(TMedium * medium);
};


#endif //TICPP_BUECHEREI_TLIBRARY_H
