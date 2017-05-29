#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;


class TTime
{
    public:
        typedef struct {
            int startpos;
            int endpos;
        } pos;
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
        void load(ifstream &file);
        string parseLine(string line, pos *position);
};
