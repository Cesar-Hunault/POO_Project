#ifndef RADIOLOGUE_H
#define RADIOLOGUE_H

#include <vector>
#include "radiographie.h"

using namespace std;

class Radiologue{

    private:
        vector<Radiographie *> list;

    public:

        void add_radio_in_list(Radiographie &);
        void radio_list_display();

};

#endif