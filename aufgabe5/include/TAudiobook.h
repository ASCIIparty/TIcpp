#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <TBook.h>
#include <TDVD.h>


class TAudiobook : virtual public TBook, public TDVD
{
    int countCDs;
    TTime PlayingTime;
    string interpret;
    int tracks;
    public:
        TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages,
                       string author, string Actors, TTime PlayingTime, string interpret, int tracks, int countCDs);
        TAudiobook();
        virtual ~TAudiobook();
        void print();
        int getCountCDs();
        string parseLine(string line, pos *position);
        void load( ifstream &file);

};

#endif // TAUDIOBOOK_H
