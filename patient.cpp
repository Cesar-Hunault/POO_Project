#include <iostream>
#include <string>
#include "patient.h"

using namespace std;

void Patient::display(){
    cout<<"Name : "<< this -> name <<endl;
    cout<<"First name : "<< this -> first_name <<endl;
    cout<<"Password : "<< this -> password <<endl;
    cout<<"Birth : "<< this -> birth_date <<endl;
    cout<<"Gender : "<< this -> gender <<endl;
}
