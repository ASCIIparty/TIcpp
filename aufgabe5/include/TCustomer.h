#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <TPerson.h>


class TCustomer : virtual public TPerson
{
    public:
        TCustomer(string name, TAddress address, TDate birthday, int CustomerNr);
        TCustomer(int CustomerNr);
        virtual ~TCustomer();
    protected:

    private:
        int CustomerNr;
};

#endif // TCUSTOMER_H
