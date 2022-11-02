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
        
        if (this->med_result != NULL){
            cout << "\tDoctor report :"<<endl;
            get_med_result();
        };
        if (this->pat_result != NULL){
            cout << "\tPatient report :"<<endl;
            get_pat_result();
        };
        
    }else{
        cout << "State : radiography is planned"<<endl;
    };
    
}

