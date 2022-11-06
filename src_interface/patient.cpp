#include <iostream>
#include <string>
#include <vector>
#include "patient.h"

using namespace std;

string Patient::patient_display(){
    string s1, s2, s3, s4, result;
    s1 = "Name : "+this->get_name();
    s2 = "First name : "+this->get_first_name();
    //this->get_password();
    //cout<<"Password protected"<<endl;
    s3 = "Birth date : "+this->get_birth_date();
    s4 = "Gender : "+this->get_gender();

    result = s1 + "\n" + s2 + "\n" + s3 + "\n" + s4;
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
