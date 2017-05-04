#include<stdio.h>
#include "TMedium.h"


TMedium::TMedium(string t, string s, TLocation l, int f, status stat)
{
    titel = t;
    signatur = s;
    location = l;
    FSK = f;
    this->stat=stat;
    //statusNames = {"verfuegbar", "ausgeliehen", "bestellt", "reserviert"};

};

char * TMedium::getStatus() //soll den Status im Klartext – also als String zurückgeben
{
    switch(stat)
    {
        case verfuegbar:    return "verfuegbar";
        case ausgeliehen:   return "ausgeliehen";
        case bestellt:      return "bestellt";
        case reserviert:    return "reserviert";
    }


}

void TMedium::print()
{
    printf("Titel: %*s\n",10, getTitle().c_str());
    printf("Signatur:%*s\n",10, getSignature().c_str());
    printf("Ort:%*s ",10,"");
    location.print();
    printf("FSK:%*s freigegeben ab %d Jahren\n",10 ,"",getFSK());
    printf("Status:%*s\n",10,getStatus());
};

int TMedium::getFSK()
{   return FSK; };

string TMedium::getSignature()
{   return signatur; }

string TMedium::getTitle()
{   return titel; };

TMedium::~TMedium()
{ printf("TMedium object %s - %s deleted\n", titel.c_str(), signatur.c_str()); };
