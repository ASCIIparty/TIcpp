/*
 * tperson.h
 *
 *  Created on: Apr 16, 2017
 *      Author: bob
 */

#ifndef TPERSON_H_
#define TPERSON_H_

#include <string>

#include "taddress.h"
#include "tdate.h"

using namespace std;

class TPerson {
private:
	string name;
	TAddress address;
	TDate birthday;

public:
	TPerson();
	TPerson(string, TAddress, TDate);
	void print();
	string getName();
	TAddress getAddress();
	TDate getBirthday();
	void setName(string);
	void setAddress(TAddress);
	void setBirthday(TDate);
	~TPerson();
};

#endif /* TPERSON_H_ */
