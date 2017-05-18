
#include <string>
#include <vector>
#include "../aufgabe2/tlocation.h"

using namespace std;

#ifndef TICPP_BUECHEREI_TMEDIUM_H
#define TICPP_BUECHEREI_TMEDIUM_H


class TMedium {
public:
    enum status {verfuegbar, ausgeliehen, bestellt, reserviert};
private:
    string titel, signatur;
    TLocation location;
    int FSK;
    char *statusNames[4];
    status stat;
     typedef struct {
        int startpos;
        int endpos;
     } pos;

public:
    TMedium(string t, string s, TLocation l, int f, status stat);
    TMedium();
    char *getStatus();
    void print();
    int getFSK();
    string getSignature();
    string getTitle();
    void load( ifstream& file);
    string parseLine(string line, pos * position);
    void setStatus(int i);
 //   ~TMedium();
};


#endif //TICPP_BUECHEREI_TMEDIUM_H
