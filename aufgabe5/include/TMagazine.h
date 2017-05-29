#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <TPrintedMedium.h>


class TMagazine : public TPrintedMedium
{
    string Designer;
    public:
        TMagazine(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages, string Designer);
        TMagazine();
        virtual ~TMagazine();
        string getDesigner();
        void print();
        string parseLine(string line, pos *position);
        void load(ifstream &file);
};

#endif // TMAGAZINE_H
