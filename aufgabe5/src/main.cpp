#include <iostream>
using namespace std;
#include "TLibraryPool.h"

int main()
{
//OLD file:    TLibraryPool LP("data.xml");
   TLibraryPool LP("data.xml");

   LP.print();
   cout << endl;

   return 0;
}
