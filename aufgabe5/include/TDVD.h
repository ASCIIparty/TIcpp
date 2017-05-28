#ifndef TDVD_H
#define TDVD_H

#include <TMedium.h>
#include <ttime.h>


class TDVD : virtual public TMedium
{
    public:
        TDVD(string t, string s, TLocation l, int f, status stat, string Actor, TTime Playtime);
        TDVD(string Actor, TTime Playtime);
        virtual ~TDVD();

    private:
        string Actor;
        TTime Playtime;
};

#endif // TDVD_H
