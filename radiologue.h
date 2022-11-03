#ifndef RADIOLOGUE_H
#define RADIOLOGUE_H

#include <vector>
#include <tuple>
#include "radiographie.h"

using namespace std;

class Radiologue{

    private:
        vector<Radiographie *> list;

    public:

        void add_radio_in_list(Radiographie &);
        void radio_list_display();

        tuple<Radiographie, Patient> add_new_radio();

        void delete_radio(int);

};

#endif