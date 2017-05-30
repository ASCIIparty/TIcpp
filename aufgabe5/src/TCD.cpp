#include "TCD.h"
#include <fstream>
#include <cstdlib>
#include "stdio.h"
using namespace std;

TCD::TCD(string title, string signatur, TLocation location, int FSK, status stat, int Tracks, string Artist) :  TMedium( titel, signatur,  location,  FSK,  stat)
{
    this->Tracks = Tracks;
    this -> Artist = Artist;
}

TCD::TCD()
{
}

TCD::~TCD()
{
    //dtor
}


void TCD::print()
{
    printf("Titel:           %s\n", TMedium::getTitle().c_str());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Artist:          %s\n", getArtist().c_str());
    printf("Tracks:          %d\n", getTracks());
    printf("Ort:             ");
    location.print();
    printf("Status:          %s", TMedium::getStatus());
};

string TCD::getArtist()
{
    return Artist;
}

int TCD::getTracks()
{
    return Tracks;
}

string TCD::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TCD::load( ifstream &file)
{
    string line;
    string value;
    pos position;
    getline(file,line);
    value=parseLine(line,&position);

    this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);

    this->signatur=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);

    if(!value.compare("Location"))
    {
        this->location.load(file);
    }
    getline (file,line);
    value=parseLine(line,&position);
    string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);

    TMedium::setStatus(atoi(sub_value.c_str()));
    getline (file,line);

    this->Artist=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);


    this->Tracks=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
    getline (file,line);
    value=parseLine(line,&position);
}
