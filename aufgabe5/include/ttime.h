#pragma once
#include<iostream>

    class TTime
    {
         private:
            int seconds;
            int minutes;
            int hour;
            time_t now;
            tm *ltm;
         public:
             TTime();
             TTime(int seconds, int minutes, int hour);
             TTime(int minutes, int hour);
             void set_seconds(int seconds);
             void set_minutes(int minutes);
             void set_hour(int hour);
             void print();
    };
