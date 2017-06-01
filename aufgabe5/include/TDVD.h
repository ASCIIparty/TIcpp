#ifndef TDVD_H
#define TDVD_H

#include <TMedium.h>
#include <ttime.h>


class TDVD : virtual public TMedium
{
    protected:
        string Actors;
        TTime PlayingTime;
    public:
        TDVD(string titel , string signatur, TLocation location, int FSK, status stat, string Actors, TTime PlayingTime);
        TDVD(string Actor, TTime Playtime);
        TDVD();
        virtual ~TDVD();
        string getActors();
        TTime getPlayingTime();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        void print();

};

#endif // TDVD_H
