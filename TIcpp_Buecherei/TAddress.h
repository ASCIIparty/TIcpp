//
// Created by bob on 25.04.17.
//

#ifndef TICPP_BUECHEREI_TADDRESS_H
#define TICPP_BUECHEREI_TADDRESS_H
#include <string>

class TAddress {
private:
    std::string street;
    std::string number;
    std::string zipcode;
    std::string town;
public:
    TAddress();
    TAddress(std::string, std::string, std::string, std::string);
    void print();
    std::string getStreet();
    std::string getNumber();
    std::string getZipcode();
    std::string getTown();
    void setStreet(std::string);
    void setNumber(std::string);
    void setZipcode(std::string);
    void setTown(std::string);
    ~TAddress();

};


#endif //TICPP_BUECHEREI_TADDRESS_H
