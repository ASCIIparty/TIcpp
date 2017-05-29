#ifndef TICPP_BUECHEREI_TLIBRARY_H
#define TICPP_BUECHEREI_TLIBRARY_H

#include <vector>
#include "TEmployee.h"
#include "TBook.h"
#include "TMagazine.h"
#include "TCD.h"
#include "TDVD.h"
#include "TAudiobook.h"

class TLibrary {
    string name;
    TAddress address;
    TEmployee *manager;
    vector<TMedium *> mediumList;
     typedef struct {
        int startpos;
        int endpos;
      } pos;
    public:
    TLibrary(string n, TAddress a, TEmployee *m);
    TLibrary();
    ~TLibrary();

    string getName();
    void print();
    vector<TMedium*>  getMediumList();
    void add(TMedium * medium);
    void load( ifstream& file);
    string parseLine(string line, pos * position);
};


#endif //TICPP_BUECHEREI_TLIBRARY_H
