#ifndef TBOOK_H
#define TBOOK_H

#include <TPrintedMedium.h>


class TBook : virtual public TPrintedMedium
{
    string author;

    public:
        TBook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author);
        TBook(string author);
        virtual ~TBook();

};

#endif // TBOOK_H
