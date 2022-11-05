#include <iostream>
#include <string>
#include "radiographie.h"

using namespace std;


// ostream& operator<<(ostream& os, const Radiographie& obj){
//     os << obj.patient.display();
//     return os;
// }

void Radiographie::radiographie_display(){
    cout << "Num exam : "<<this->get_num_exam()<<endl;
    this->get_type();
    this->get_patient();
    this->get_id_medecin();
    this->get_date();
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

