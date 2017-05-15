
#ifndef TICPP_BUECHEREI_TPERSON_H
#define TICPP_BUECHEREI_TPERSON_H


#include "../aufgabe2/taddress.h"
#include "../aufgabe1/tdate.h"
#include<stdio.h>
#include <string>

using namespace std;


class TPerson {
private:
    string name;
    TAddress address;
    TDate birthday;

public:


     typedef struct {
        int startpos;
        int endpos;
     } pos;
    TPerson(string, TAddress, TDate);
    TPerson();
    void print();
    string getName();
    TAddress getAddress();
    TDate getBirthday();
    void setName(string);
    void setAddress(TAddress);
    void setBirthday(TDate);
    void load( ifstream& file);
    string parseLine(string line, pos * position);
    ~TPerson()
    {    printf("TPerson object %s deleted.\n", name.c_str()); };

};


#endif //TICPP_BUECHEREI_TPERSON_H
