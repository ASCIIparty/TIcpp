
#include<iostream>
#include<cstdlib>
#include<string>
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
TDate TDate:: operator + (int days){
    int rest=days+this->day;
    int divisor;
    int loop;
    int last;
    cout<<"number days "<<days<<endl;
    int day, month, year;
    //day= this->day;
    month=this->month;
    year=this->year;

    do{
        if(!(month%2)){
         divisor=31;
        }
        else if(month==2){
            if(year%4 ==0){
            divisor=29;
            }
            else{
                divisor= 28;
            }

        }
        else{
            divisor= 30;

        }
        last=rest;
      rest= rest-divisor;
      if(rest>0){
            if(month==12){
                month=1;
                year++;
            }
        else month++;
      }
    }while(rest>0);

    TDate date(last,month,year);
    return date;
}

string TDate:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

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
void TDate::load( ifstream& file)
{
    string line;
    string value;
    pos position;
    getline(file,line);
    value=parseLine(line,&position);
    string  sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    this->day=atoi(sub_value.c_str()) ;
    getline (file,line);
    value=parseLine(line,&position);
    sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    this->month=atoi(sub_value.c_str()) ;
    getline (file,line);
    value=parseLine(line,&position);
    sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    this->year=atoi(sub_value.c_str());
    //cout<<year<<"year"<<endl;
    getline (file,line);
}

