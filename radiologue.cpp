#include <iostream>
#include <vector>
#include "radiologue.h"
#include "radiographie.h"

using namespace std;

void Radiologue::add_radio_in_list(Radiographie &radio){
    this->list.push_back(&radio);
};

void Radiologue::radio_list_display(){
    for (int i = 0; i < this->list.size(); ++i){
        Radiographie list = *this->list[i];
        cout<<"\n############### Radiographie n°"<<i+1<<" ###############"<<endl;
        list.radiographie_display();
    }
};