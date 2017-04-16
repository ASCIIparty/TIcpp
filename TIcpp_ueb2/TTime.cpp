/*
 * TTime.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: bob
 */

#include "ttime.h"
#include <stdio.h>
#include <ctime>

TTime::TTime()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    hour = timePtr-> tm_hour;
    minute = timePtr->tm_min;
    second = timePtr->tm_sec;
}
TTime::TTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void TTime::print()
{
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

TTime::~TTime()
{
    printf("TTime object deleted.\n");
}
