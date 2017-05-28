#ifndef TCD_H
#define TCD_H

#include <TMedium.h>


class TCD : virtual public TMedium
{
    public:
        TCD(string t, string s, TLocation l, int f, status stat, int Tracks, string Artist);
        virtual ~TCD();
    private:
        int Tracks;
        string Artist;
};

#endif // TCD_H
