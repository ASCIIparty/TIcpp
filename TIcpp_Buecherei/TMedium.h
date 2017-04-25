#include <string>
#include <vector>
#include "TLocation.h"

using namespace std;

#ifndef TICPP_BUECHEREI_TMEDIUM_H
#define TICPP_BUECHEREI_TMEDIUM_H


class TMedium {
    string titel, signatur;
    TLocation location;
    int FSK;
    vector<string> statusNames = {"verfuegbar", "ausgeliehen", "bestellt", "reserviert"};
public:
    enum status {verfuegbar, ausgeliehen, bestellt, reserviert};
    status status;

/*    Dieser Aufzählungstyp soll in der Klasse öffentlich angelegt werden, so
            dass z.B. die Abfrage des Status lesbarer wird:
    if ((Status & TMedium::verfuegbar) == TMedium::verfuegbar)
    Status = Tmedium::ausgeliehen;
*/
    TMedium(string t, string s, TLocation l, int f)
    {
        titel = t;
        signatur = s;
        location = l;
        FSK = f;
    };
    string getStatus() //soll den Status im Klartext – also als String zurückgeben
    {
        return statusNames[status];
    }
    void print()
    {
        printf("%s\n", getTitle().c_str());
        printf("%s\n", getSignature().c_str());
        location.print();
        printf("freigegeben ab %d Jahren\n", getFSK());

    };

    int getFSK()
    { return FSK; };

    string getSignature()
    {   return signatur; }

    string getTitle()
    {   return titel; };
    ~TMedium()
    { printf("TMedium object %s - %s deleted\n", titel.c_str(), signatur.c_str()); };
};


#endif //TICPP_BUECHEREI_TMEDIUM_H
