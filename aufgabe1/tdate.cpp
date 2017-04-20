
#include<iostream>
#include "tdate.h"
using namespace std;

TDate::TDate()
{
    now = time(0);
    ltm=localtime(&now);
    year= ltm->tm_year+1900;
    month=ltm->tm_mon+1;
    day=ltm->tm_mday;
}
 TDate::TDate(int day, int month, int year)
 {
    this->day=day;
    this->month=month;
    this->year=year;

}
void TDate::set_day(int day)
{
    this->day=day;
}
void TDate::set_month(int month)
{
    this->month=month;
}
void TDate::set_year(int year)
{
    this->year=year;
}
void TDate::print()
{
    cout << day <<"."<<month<<"."<<year<< endl;
}
int TDate::get_day()
{
    return day;
}
int TDate::get_month()
{
    return month;
}
int TDate::get_year()
{
    return year;
}

