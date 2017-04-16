#include "tdate.h"
#include <stdio.h>
#include <ctime>

TDate::TDate()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    day = timePtr->tm_mday;
    month = timePtr->tm_mon;
    year = timePtr->tm_year;
}

TDate::TDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void TDate::print()
{
    printf("%02d.%02d.%04d\n", day,month,year);
}

TDate::~TDate()
{ }

int TDate::getDay() {
    return day;
}

void TDate::setDay(int day) {
    TDate::day = day;
}

int TDate::getMonth() {
    return month;
}

void TDate::setMonth(int month) {
    TDate::month = month;
}

int TDate::getYear() {
    return year;
}

void TDate::setYear(int year) {
    TDate::year = year;
}
