#include "TAudiobook.h"
#include "TBook.h"
#include "TDVD.h"
#include "ttime.h"


TAudiobook::TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author, string Actors, TTime PlayingTime, int countCDs)
            : TBook(title, signature, location, FSK, stat, Pages, author), TDVD(titel , signatur, location, FSK, stat, Actors, PlayingTime)
{
    this->countCDs = countCDs;
}

TAudiobook::TAudiobook()
{

}

TAudiobook::~TAudiobook()
{
    //dtor
}

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
