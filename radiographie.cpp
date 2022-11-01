#include <iostream>
#include <string>
#include "radiographie.h"

using namespace std;


// ostream& operator<<(ostream& os, const Radiographie& obj){
//     os << obj.patient.display();
//     return os;
// }

void Radiographie::display(){
    cout<<"Num exam : "<< this -> num_examen <<endl;
    cout<<"Type : "<< this -> type <<endl;
    this->get_patient();
    cout<<"Medecin Id : "<< this -> id_medecin <<endl;
    cout<<"Date : "<< this -> date <<endl;
    if (this->state){
        cout << "State : radiography is performed"<<endl;
    }else{
        cout << "State : radiography is planned"<<endl;
    };
}

