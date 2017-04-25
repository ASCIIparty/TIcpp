#ifndef TICPP_BUECHEREI_TDATE_H
#define TICPP_BUECHEREI_TDATE_H


class TDate {
private:
    int day, month, year;
public:
    int getDay();

    void setDay(int day);

    int getMonth();

    void setMonth(int month);

    int getYear();

    void setYear(int year);

public:
    TDate();
    TDate(int d, int m, int y);
    ~TDate();
    void print();

};


#endif //TICPP_BUECHEREI_TDATE_H
