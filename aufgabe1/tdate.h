
#pragma once
#include <iostream>
#include <ctime>
    class TDate
    {
        private:
            int day;
            int month;
            int year;
            time_t now;
            tm *ltm;
        public:
            TDate();
            TDate(int day, int month, int year);
            void set_day(int day);
            void set_month(int month);
            void set_year(int year);
            int get_day();
            int get_month();
            int get_year();
            void print();

    };
