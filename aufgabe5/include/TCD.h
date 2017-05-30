#ifndef TCD_H
#define TCD_H

#include <TMedium.h>


class TCD : virtual public TMedium
{
        int Tracks;
        string Artist;
    public:
        TCD(string t, string s, TLocation l, int f, status stat, int Tracks, string Artist);
        TCD();
        virtual ~TCD();
        void load( ifstream &file);
        int getTracks();
        string getArtist();
        string parseLine(string line, pos *position);
        void print();
};

#endif // TCD_H
