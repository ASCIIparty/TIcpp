#include "TDVD.h"
#include <fstream>
#include <cstdlib>

TDVD::TDVD(string titel , string signatur, TLocation location, int FSK, status stat, string Actors, TTime PlayingTime) : TMedium(titel,  signatur,  location,  FSK,  stat)
{
    this->Actors = Actors;
    this->PlayingTime = PlayingTime;
}

TDVD::TDVD()
{

}

TDVD::~TDVD()
{
    //dtor
}


void TDVD::print()
{
    printf("Schauspieler:    %s\n", getActors().c_str());
    printf("Spielzeit:       %s\n", getPlayingTime());
    printf("Titel:           %s\n", TMedium::getTitle().c_str());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n",TMedium::getFSK());
    printf("Status:          %s", TMedium::getStatus());
};

string TDVD::getActors()
{
    return Actors;
}

TTime TDVD::getPlayingTime()
{
    return PlayingTime;
}

string TDVD::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TDVD::load( ifstream &file)
{
    string line;
    string value;
    pos position;
    getline(file,line);
    value=parseLine(line,&position);

    this->Actors=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);

    this->PlayingTime.load(file);
    getline (file,line);
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

    this->FSK=atoi(sub_value.c_str());
    getline (file,line);
    value=parseLine(line,&position);
    sub_value =line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);

    TMedium::setStatus(atoi(sub_value.c_str()));
    getline (file,line);
}
