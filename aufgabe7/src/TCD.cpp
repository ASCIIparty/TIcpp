#include "TCD.h"
#include <fstream>
#include <cstdlib>
#include "stdio.h"
using namespace std;


/*TCD::TCD(string title, string signatur, TLocation location, int FSK, status stat, int Tracks, string Artist) :  TMedium( titel, signatur,  location,  FSK,  stat)
{
    this->Tracks = Tracks;
    this -> Artist = Artist;
}*/

TCD::TCD()
{
}

TCD::~TCD()
{
    printf("Die CD %s wurde geloescht.\n", getTitle().c_str());
}


void TCD::print()
{
    printf("Interpret:       %s\n", getInterpret().c_str());
    printf("Anz. Tracks:     %d\n", getTracks());
    printf("Titel:           %s\n", TMedium::getTitle().c_str());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n", getFSK());
    printf("Status:          %s", TMedium::getStatus());
};

string TCD::getInterpret()
{
    return Interpret;
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
    TMedium::stat=verfuegbar;
    while((line.find("</CD>") == -1))
    {

        if(!value.compare("Location"))
        {
            this->location.load(file);
        }
        else if(!value.compare("Title"))
        {
            this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Signatur"))
        {
            this->signatur=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Status"))
        {
            string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            TMedium::setStatus(atoi(sub_value.c_str()));
        }
        else if(!value.compare("Interpret"))
        {
            this->Interpret=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Tracks"))
        {
            this->Tracks=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
        }
        else if(!value.compare("FSK"))
        {
           // cout<<FSK<<"CD??"<<endl;
            string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            TMedium::FSK=atoi(sub_value.c_str());
        }
        getline (file,line);
        value=parseLine(line,&position);

    }

}
