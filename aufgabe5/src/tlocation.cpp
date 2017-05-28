#include <iostream>
#include <fstream>
#include <string>
#include "tlocation.h"

using namespace std;
TLocation::TLocation()
{
    Section= "Buero";
    Rack= "Fachzum Einsortieren";
}
TLocation::TLocation(string Section, string Rack)
{
    this->Section=Section;
    this->Rack=Rack;
}
void TLocation::set_Section(string Section)
{
    this->Section=Section;
}
void  TLocation::set_Rack(string Rack)
{
    this->Rack=Rack;
}
string  TLocation::get_Section()
{
    return Section;
}
string  TLocation::get_Rack()
{
    return Rack;
}
void TLocation::print()
{
    cout <<"Abt.:"<< Section<<";"<<" Regal: "<<Rack<< endl;
}
string  TLocation:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

}
 void TLocation::load( ifstream& file){
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->Section=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
   // cout<<Section<<endl;
    value=parseLine(line,&position);
    this->Rack=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    //cout<<Rack<<endl;
    getline (file,line);

 }


