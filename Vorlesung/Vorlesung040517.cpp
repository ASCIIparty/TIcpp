#include <iostream>
#include <iomanip>

using namespace std;


int Vorlesung045017() {
    cout << 7 << "Text" << 'a' << 3.1415 << endl;
    cout.put('a');
    cout.width(3); // nur 1 Ausgabe
    cout << 7; //-> _ _ 7
    cout.fill('x'); // gilt dauerhaft
    cout.width(3);
    cout << 3; //xx3

    // MANIPULATOR AUFRUF
    cout << "Text" << Tab << "Text";

    return 0;
}

void KLAUSURAUFGABE()
{
    // schreiben sie  ihren eigenen manipulator
    ostream & Tab(ostream &ostr)
    {
        return ostr << "\t";
    }
}

void print()
{
    char tmp = cout.fill();
    cout.fill('.');
    cout.width(5);
    cout << 5;
    cout.fill(tmp);

    cout.width(5);
    cout << '(' << 5 << ')' << endl; // -> (_ _ _ _ 5)

    cout.flags(ios::hex | ios::left);
    cout.flags(ios::fixed);
    cout.flags(ios::scientific);

    cout.setf(ios::hex, ios::basefield);

    //manipulatoren <iomanip>


}