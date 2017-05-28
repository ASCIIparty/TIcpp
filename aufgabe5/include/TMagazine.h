#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <TPrintedMedium.h>


class TMagazine : public TPrintedMedium
{
    string Designer;
    public:
        TMagazine(string t, string s, TLocation l, int f, status stat, int Pages, string Designer);
        virtual ~TMagazine();

};

#endif // TMAGAZINE_H
