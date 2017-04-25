#include <iostream>

using namespace std;

#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "ttime.h"

int main()
{
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

   return 0;
}
