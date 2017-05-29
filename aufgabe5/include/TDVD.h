#ifndef TDVD_H
#define TDVD_H

#include <TMedium.h>
#include <ttime.h>


class TDVD : virtual public TMedium
{
    protected:
        string Actor;
        TTime PlayingTime;
    public:
        TDVD(string titel , string signatur, TLocation location, int FSK, status stat, string Actor, TTime PlayingTime);
        TDVD(string Actor, TTime Playtime);
        virtual ~TDVD();
};

#endif // TDVD_H
