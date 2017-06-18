
#include <string>
#include <vector>
#include "TLocation.h"

using namespace std;

#ifndef TICPP_BUECHEREI_TMEDIUM_H
#define TICPP_BUECHEREI_TMEDIUM_H


class TMedium {
protected:
    string titel;
    string signatur;
    enum status {verfuegbar, ausgeliehen, bestellt, reserviert};
protected:
    TLocation location;
    int FSK;
    char * statusNames[4];
    status stat;
     typedef struct {
        int startpos;
        int endpos;
     } pos;

public:
    TMedium(string title, string signature, TLocation location, int FSK, status stat);
    TMedium();
    char * getStatus();
    virtual void print();
    int getFSK();
    string getSignature();
    string getTitle();
    virtual ~TMedium();
    virtual void load( ifstream& file);
    virtual string parseLine(string line, pos * position);
    void setStatus(int i);
    ostream& operator<<(const TMedium& obj);
};


#endif //TICPP_BUECHEREI_TMEDIUM_H
