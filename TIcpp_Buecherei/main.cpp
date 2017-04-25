#include <iostream>
#include "TDate.h"
#include "TTime.h"
#include "TPerson.h"
#include "TLocation.h"


#include "TAddress.h"
#include "TPerson.h"
#include "TMedium.h"
#include "TLibrary.h"
#include "TLibrarypool.h"

using namespace std;

int main() {
    TDate D1, D2(1, 5, 2017);
    TTime T1, T2(6, 32, 27), T3(17, 45);

    cout << "\nKlasse TDate:" << endl;
    cout << "Standardkonstruktor Heutiges Datum (D1):     ";   D1.print();   cout << endl;
    cout << "Konstruktor         Tag der Arbeit (D2):     ";   D2.print();   cout << endl;

    cout << "\nKlasse TTime:" << endl;
    cout << "Standardkonstruktor Aktuelle Uhrzeit (T1):   ";   T1.print();   cout << endl;
    cout << "Konstruktor         Zeit zum Aufstehen (T2): ";   T2.print();   cout << endl;
    cout << "Konstruktor         Uebungsbeginn (T3):      ";   T3.print();   cout << endl;

    TLocation L1, L2("Technik", "Computer"); //Technik-Abteilung im Computer-Regal
    TDate Geburtstag(17, 11, 1984);
    TAddress A1("Luxemburger Str.", "10", "D-13351", "Berlin");
    TAddress Adresse("Berliner Str.", "21-23", "10876", "Berlin");
    TPerson Egon("Egon Mustermann", Adresse, Geburtstag);

    cout << "Klasse TLocation:" << endl;
    cout << "Standardkonstruktor fuer neue Buecher:    ";     L1.print();   cout << endl;
    cout << "Konstruktor Technik-Abt., Computer-Regal: ";     L2.print();   cout << endl;

    cout << "\nKlasse TAddress:" << endl;
    cout << "Konstruktor Adresse der Beuth Hochschule:\n";    A1.print();   cout << endl;

    cout << "\nKlasse TPerson:" << endl;
    cout << "Konstruktor Egon Mustermann:\n";                 Egon.print(); cout << endl;
// ----- Ü3
    TDate D1(17, 11, 1963);

    TLocation L1("Technik", "Computer");
    TLocation L2("Romane", "Krimi");
    TLocation L3("Kinder", "Comics");
    TLocation L4("DVDs", "Horror");

    TAddress A1("Buchallee", "15a", "13315", "Berlin");
    TAddress A2("Schlossstr.", "117", "12077", "Berlin");
    TAddress A3("Muellerstr.", "39", "13309", "Berlin");

    TPerson Leitung("Egon Mustermann", A2, D1);
    TPerson FL1("Peter Mueller", A3, D1);
    TPerson FL2("Erika Mueller", A3, D1);
    TPerson K1("Marion Schulz", A1, D1);
    TPerson K2("Stefan Meier", A2, D1);

    TMedium M1("Programmieren in C", "PC99", L1, 0, TMedium::ausgeliehen);
    TMedium M2("Der Hexer", "He83", L2, 12, TMedium::verfuegbar);
    TMedium M3("Asterix und Obelix", "KC17", L3, 0, TMedium::verfuegbar);
    TMedium M4("Der Werwolf", "WW175", L4, 16, TMedium::ausgeliehen);

    TLibrary LWedding("Wedding", A1, &FL1);
    TLibrary LSteglitz("Steglitz", A2, &FL2);

    TLibraryPool LP("Buechereiverband Berlin", &Leitung);


    LWedding.add(&M1);
    LWedding.add(&M2);

    LSteglitz.add(&M3);
    LSteglitz.add(&M4);

    LP.add(&LWedding);
    LP.add(&LSteglitz);
    LP.add(&K1);
    LP.add(&K2);

    LP.print();
    cout << endl;

    return 0;
}