#ifndef TPRINTEDMEDIUM_H
#define TPRINTEDMEDIUM_H

#include <TMedium.h>


class TPrintedMedium : virtual public TMedium
{
    private:
        int Pages;
    public:
        TPrintedMedium(string t, string s, TLocation l, int f, status stat, int Pages);
        virtual ~TPrintedMedium();
};

#endif // TPRINTEDMEDIUM_H
