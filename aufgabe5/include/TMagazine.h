#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <TPrintedMedium.h>


class TMagazine : public TPrintedMedium
{
    string Designer;
    public:
        TMagazine(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages, string Designer);
        virtual ~TMagazine();

};

#endif // TMAGAZINE_H
