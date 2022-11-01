#include <string>
#include <iostream>
#include "utilisateur.h"

using namespace std;

void Utilisateur::display(){
    cout<<"name : "<< this -> name <<endl;
    cout<<"first name : "<< this -> first_name <<endl;
    cout<<"password : "<< this -> password <<endl;

}
