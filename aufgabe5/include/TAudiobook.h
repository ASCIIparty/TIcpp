#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <TBook.h>
#include <TDVD.h>


class TAudiobook : virtual public TBook, virtual public TDVD
{
    int countCDs;
    public:
        TAudiobook(string t, string s, TLocation l, int f, status stat, int Pages, string author,
                    string Actor, TTime Playtime, int countCDs);
        virtual ~TAudiobook();
};

#endif // TAUDIOBOOK_H
