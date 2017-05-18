
#ifndef TICPP_BUECHEREI_TLIBRARY_H
#define TICPP_BUECHEREI_TLIBRARY_H

#include <vector>
#include "TMedium.h"
#include "TPerson.h"


class TLibrary {
    string name;
    TAddress address;
    TPerson *manager;
    vector<TMedium *> mediumList;
     typedef struct {
        int startpos;
        int endpos;
      } pos;
    public:
    TLibrary(string n, TAddress a, TPerson *m);
    TLibrary();
//    ~TLibrary();
    string getName();
    void print();
    vector<TMedium*>  getMediumList();
    void add(TMedium * medium);
    void load( ifstream& file);
    string parseLine(string line, pos * position);
};


#endif //TICPP_BUECHEREI_TLIBRARY_H
