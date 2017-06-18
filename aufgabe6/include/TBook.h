#ifndef TBOOK_H
#define TBOOK_H

#include <TPrintedMedium.h>


class TBook : virtual public TPrintedMedium
{
    protected:
        string author;

    public:
        TBook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author);
        TBook(string author);
        TBook();
        virtual ~TBook();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        string getAuthor();
        void print();

};

#endif // TBOOK_H
