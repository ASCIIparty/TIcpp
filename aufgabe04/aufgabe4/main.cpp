#include <iostream>
using namespace std;
#include "../aufgabe3/tlibrarypool.h"
int main()
{
 TLibraryPool LP("data.xml");
 LP.print();
 cout << endl;
 return 0;
}
