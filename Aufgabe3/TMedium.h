
#include <string>
#include <vector>
#include "../aufgabe2/tlocation.h"

using namespace std;

#ifndef TICPP_BUECHEREI_TMEDIUM_H
#define TICPP_BUECHEREI_TMEDIUM_H


class TMedium {
    string titel, signatur;
    TLocation location;
    int FSK;
    char * statusNames[4];
public:
    enum status {verfuegbar, ausgeliehen, bestellt, reserviert};
    status stat;

/*   enum status soll in der Klasse öffentlich angelegt werden, so
            dass z.B. die Abfrage des Status lesbarer wird:
    if ((Status & TMedium::verfuegbar) == TMedium::verfuegbar)
    Status = Tmedium::ausgeliehen;
*/
    TMedium(string t, string s, TLocation l, int f, status stat);
    char * getStatus();
    void print();
    int getFSK();
    string getSignature();
    string getTitle();
    ~TMedium();
};


#endif //TICPP_BUECHEREI_TMEDIUM_H
