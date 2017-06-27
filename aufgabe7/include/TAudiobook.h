#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <TBook.h>
#include <TCD.h>
#include <ttime.h>


class TAudiobook : public TBook, public TCD
{
    int countCDs;
    TTime PlayingTime;

    public:
   //     TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages,
   //                    string author, string Actors, TTime PlayingTime, string interpret, int tracks, int countCDs);
        TAudiobook();
        virtual ~TAudiobook();
        void print();
        int getCountCDs();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        int getTracks();
};

#endif // TAUDIOBOOK_H
