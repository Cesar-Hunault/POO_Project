#include <string>
#include <iostream>
#include "utilisateur.h"

using namespace std;

string Utilisateur::utilisateur_display(){
    string result1 = this->name;
    string result2 = this->first_name;
    string result3 = result1 + "\n" + result2;
    
    //this->get_password();
    // cout<<"Password protected"<<endl;
    return result3;

}
