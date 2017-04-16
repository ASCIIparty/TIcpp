#ifndef TDATE_H
#define TDATE_H


class TDate
{
    private:
        int day, month, year;
    public:
        TDate();
        TDate(int d, int m, int y);
        ~TDate();
        void print();
};

#endif // TDATE_H
