#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <TBook.h>
#include <TDVD.h>


class TAudiobook : virtual public TBook, public TDVD
{
    int countCDs;
    TTime PlayingTime;
    public:
        TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author, string Actors, TTime PlayingTime, int countCDs);
        TAudiobook();
        virtual ~TAudiobook();
        void print();
        int getCountCDs();
};

#endif // TAUDIOBOOK_H
