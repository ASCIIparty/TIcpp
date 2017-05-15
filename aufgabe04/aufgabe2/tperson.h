#pragma once
#include <iostream>
#include <string>
#include "../aufgabe1/tdate.h"
using namespace std;
class TPerson
    {
        private:
            string Name;
            TDate Birthday;
            TAddress Adress;

        public:
            TPerson(string name,TAddress Adress, TDate Birthday );
            void set_Name(string Name);
            void set_Birthday(TDate Birthday);
            void set_Adresse(TAddress Adress);
            string get_Name();
            TDate get_Birthday();
            TAddress get_Address();
            void print();
    };
