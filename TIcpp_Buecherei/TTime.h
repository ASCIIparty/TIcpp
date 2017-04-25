//
// Created by bob on 25.04.17.
//

#ifndef TICPP_BUECHEREI_TTIME_H
#define TICPP_BUECHEREI_TTIME_H


class TTime {
private:
    int hour, minute, second;
public:
    TTime();
    TTime(int, int, int = 0);
    void print();
    virtual ~TTime();

};


#endif //TICPP_BUECHEREI_TTIME_H
