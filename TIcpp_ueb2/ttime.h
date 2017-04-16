#ifndef TTIME_H
#define TTIME_H


class TTime
{
    private:
        int hour, minute, second;
    public:
        TTime();
        TTime(int, int, int = 0);
        void print();
        virtual ~TTime();

};

#endif // TTIME_H
