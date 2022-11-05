#include <string>
#include <iostream>
#include "utilisateur.h"

using namespace std;

void Utilisateur::utilisateur_display(){
    this->get_name();
    this->get_first_name();
    //this->get_password();
    cout<<"Password protected"<<endl;

}
