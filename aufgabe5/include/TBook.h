#ifndef TBOOK_H
#define TBOOK_H

#include <TPrintedMedium.h>


class TBook : public TPrintedMedium
{
    string author;

    public:
        TBook(string t, string s, TLocation l, int f, status stat, int Pages, string author);
        virtual ~TBook();

};

#endif // TBOOK_H
