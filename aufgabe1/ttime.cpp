
#include<iostream>
#include <ctime>
#include "ttime.h"
using namespace std;

TTime::TTime()
{
    now = time(0);
    ltm=localtime(&now);
    seconds= ltm->tm_sec;
    minutes=ltm->tm_min;
    hour=ltm->tm_hour;
}
 TTime::TTime(int hour, int minutes,int seconds )
 {
    this->seconds=seconds;
    this->minutes=minutes;
    this->hour=hour;
}
TTime::TTime( int hour,int minutes )
 {
    this->seconds=0;
    this->minutes=minutes;
    this->hour=hour;
}
void TTime::set_seconds(int day)
{
    this->seconds=seconds;
}
void TTime::set_minutes(int month)
{
    this->minutes=minutes;
}
void TTime::set_hour(int year)
{
    this->hour=hour;
}
void TTime::print()
{
    cout <<hour  <<":"<<minutes<<":"<<seconds<< endl;
}
