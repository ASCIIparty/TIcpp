#pragma once
#include <iostream>
#include <string>
using namespace std;
    class TAddress
    {
        private:
            string Street;
            string Number;
            string Zipcode;
            string Town;
            typedef struct {
                int startpos;
                int endpos;
            } pos;

        public:
            TAddress();
            TAddress(string Street, string Number, string Zipcode, string Town);
            void set_Street(string Street);
            void set_Number(string Number);
            void set_Zipcode(string Zipcode);
            void set_Town(string Town);
            string get_Street();
            string get_Number();
            string get_Zipcode();
            string get_Town();
            void print();
            void load( ifstream& file);
            string parseLine(string line, pos * position);
            ~TAddress();
    };
