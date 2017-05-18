#pragma once
#include <iostream>
#include <string>
using namespace std;
class TLocation
    {
        private:
            string Section;
            string Rack;
            typedef struct {
                int startpos;
                int endpos;
            } pos;

        public:
            TLocation();
            ~TLocation();
            TLocation(string Section, string Rack);
            void set_Section(string Section);
            void set_Rack(string Rack);
            string get_Section();
            string get_Rack();
            void print();
            void load( ifstream& file);
            string parseLine(string line, pos * position);
    };
