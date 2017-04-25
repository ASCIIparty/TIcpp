#ifndef TICPP_BUECHEREI_TLOCATION_H
#define TICPP_BUECHEREI_TLOCATION_H

using namespace std;

class TLocation {
private:
    string section;
    string rack;
public:
    TLocation();
    TLocation(string, string);
    void print();
    string getSection();
    string getRack();
    ~TLocation();

};


#endif //TICPP_BUECHEREI_TLOCATION_H
