
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
    char * statusNames[4];
    status stat;

/*   enum status soll in der Klasse öffentlich angelegt werden, so
            dass z.B. die Abfrage des Status lesbarer wird:
    if ((Status & TMedium::verfuegbar) == TMedium::verfuegbar)
    Status = Tmedium::ausgeliehen;
*/
public:
    TMedium(string t, string s, TLocation l, int f, status stat);
    char * getStatus();
    void print();
    int getFSK();
    string getSignature();
    string getTitle();
    ~TMedium();
};


#endif //TICPP_BUECHEREI_TMEDIUM_H
