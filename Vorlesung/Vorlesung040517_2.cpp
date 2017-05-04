//
// Created by bob on 04.05.17.
//

#include <iostream>
#include <fstream>

using namespace std;

void IOtreams()
{

    ifstream Q;
    ofstream Z;

    Q.open("Text.txt", ios::in); // | ios::binary
    Z.open("Text.bak", ios::out);
    if(Q)
    {
        // Do something...
    }
    Q.close();
    //oder wenn ich sicher sein will das ich nichts vergessen hab ..:
    fcloseall();
}
