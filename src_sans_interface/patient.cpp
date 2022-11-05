#include <iostream>
#include <string>
#include <vector>
#include "patient.h"

using namespace std;

void Patient::patient_display(){
    this->get_name();
    this->get_first_name();
    //this->get_password();
    cout<<"Password protected"<<endl;
    this->get_birth_date();
    this->get_gender();
}

void Patient::add_result(PatientResult &res){
    this->resultats.push_back(&res);
}

void Patient::result_display(){
    for (int i = 0; i < this->resultats.size(); ++i){
        PatientResult result = *this->resultats[i];
        cout<<"\tResult n°"<<i+1<<endl;
        result.patient_result_display();
    }
}
