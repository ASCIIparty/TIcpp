#include "TBook.h"
#include <stdio.h>
#include <fstream>
#include <cstdlib>

TBook::TBook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author)
        : TPrintedMedium( title, signature, location, FSK, stat, author, Pages)
{
    this->author = author;
}

TBook::TBook(string author)
{
    this->author = author;
}

TBook::TBook()
{
}

TBook::~TBook()
{
    //dtor
}

void TBook::print()
{
    printf("Autor:           %s\n", getAuthor().c_str());
    printf("Anz. Seiten:     %d\n", TPrintedMedium::getPages());
    printf("Titel:           %s\n", getTitle().c_str());
    printf("Signatur:        %s\n",getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n",TMedium::getFSK());
    printf("Status:          %s", TMedium::getStatus());
};

string TBook::getAuthor()
{
    return author;
}

string TBook::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TBook::load( ifstream &file)
{
    string line;
    string value;
    pos position;
    getline(file,line);
    value=parseLine(line,&position);

    this->author=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);

    this->Pages=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
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
