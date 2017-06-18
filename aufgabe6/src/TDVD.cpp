#include "TDVD.h"
#include <fstream>
#include <cstdlib>

TDVD::TDVD(string titel, string signatur, TLocation location, int FSK, status stat, string Actors,
           TTime PlayingTime) : TMedium(titel,  signatur,  location,  FSK,  stat)
{
    this->Actors = Actors;
    this->PlayingTime = PlayingTime;
}

TDVD::TDVD()
{
}

TDVD::~TDVD()
{
    printf("Das DVD %s wurde geloescht.\n", getTitle().c_str());

}


void TDVD::print()
{
    printf("Schauspieler:    %s\n", getActors().c_str());
    printf("Spielzeit:       ");
    PlayingTime.print();
    printf("Titel:           %s\n", TMedium::getTitle().c_str());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n",TMedium::getFSK());
    //printf("Status:          %s", TMedium::getStatus());
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
    while((line.find("</DVD>") == -1))
    {
        if(!value.compare("Location"))
        {
            this->location.load(file);
        }
        else if(!value.compare("PlayingTime"))
        {
            getline (file,line);
            this->PlayingTime.load(file);
            getline (file,line);
        }
        else if(!value.compare("Title"))
        {
            this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);

        }
        else if(!value.compare("Signatur"))
        {
            this->signatur=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);

        }
        else if(!value.compare("FSK"))
        {
            string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            this->FSK=atoi(sub_value.c_str());
        }
        else if(!value.compare("Status"))
        {
            string sub_value =line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            TMedium::setStatus(atoi(sub_value.c_str()));


        }
        else if(!value.compare("Actors"))
        {
            this->Actors=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);


        }
        getline (file,line);
        value=parseLine(line,&position);


    }


}
