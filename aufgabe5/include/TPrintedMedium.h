#ifndef TPRINTEDMEDIUM_H
#define TPRINTEDMEDIUM_H

#include <TMedium.h>


class TPrintedMedium : virtual public TMedium
{
    private:
        int Pages;
    public:
        TPrintedMedium();
        TPrintedMedium(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages);
        TPrintedMedium(int Pages);
        virtual ~TPrintedMedium();
};

#endif // TPRINTEDMEDIUM_H
