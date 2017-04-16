#ifndef TADDRESS_H_
#define TADDRESS_H_

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

#endif /* TADDRESS_H_ */
