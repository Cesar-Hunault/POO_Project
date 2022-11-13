#include <iostream>
#include <string>
#include <vector>
#include "patient.h"

using namespace std;

string Patient::patient_display(){
    
    string result;
    
    result += "Id : "+this->get_id();
    result += "\nName : "+this->get_name();
    result += "\nFirst name : "+this->get_first_name();
    result += "\nBirth date : "+this->get_birth_date();
    result += "\nGender : "+this->get_gender();
    
    return result;
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
