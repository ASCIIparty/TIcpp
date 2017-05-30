#include "TAudiobook.h"
#include "TBook.h"
#include "TDVD.h"
#include "ttime.h"


TAudiobook::TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages,
                       string author, string Actors, TTime PlayingTime, string interpret, int tracks, int countCDs)
            : TBook(title, signature, location, FSK, stat, Pages, author),
              TDVD(titel , signatur, location, FSK, stat, Actors, PlayingTime)
{
    this->interpret = interpret;
    this->tracks = tracks;
    this->countCDs = countCDs;
}

TAudiobook::TAudiobook()
{ }

TAudiobook::~TAudiobook()
{ }

void TAudiobook::print()
{
    printf("Titel:           %s\n", TPrintedMedium::getTitle().c_str());
    printf("Anzahl CDs:      %d\n", getCountCDs());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n",TMedium::getFSK());
    printf("Status:          %s", TMedium::getStatus());
}

int TAudiobook::getCountCDs()
{
    return countCDs;
}

string TAudiobook::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TAudiobook::load( ifstream &file)
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

    this->author=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
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

    this->interpret=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);

    this->tracks=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
    getline (file,line);
    value=parseLine(line,&position);

    this->Pages=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
    getline (file,line);
    value=parseLine(line,&position);

    this->countCDs=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
    getline (file,line);
    value=parseLine(line,&position);

}
