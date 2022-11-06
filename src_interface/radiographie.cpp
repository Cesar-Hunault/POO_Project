#include <iostream>
#include <string>
#include "radiographie.h"

using namespace std;


// ostream& operator<<(ostream& os, const Radiographie& obj){
//     os << obj.patient.display();
//     return os;
// }

string Radiographie::radiographie_display(){
    string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, result;
    s1 = this->get_num_exam();
    s2 = "Type of radiography : "+this->get_type();
    s3 = "\tPatient : \n"+this->get_patient();
    s4 = "Doctor Id : "+this->get_id_medecin();
    s5 = "Date : "+this->get_date();
    if (this->state){
        s6 = "State : radiography is performed\n";
        
        if (this->med_result != NULL){
            s7 = "\tDoctor report :\n";
            s8 = get_med_result();
        };
        if (this->pat_result != NULL){
            s9 = "\tPatient report :\n";
            s10 = get_pat_result();
        };
        
    }else{
        s6 = "State : radiography is planned\n";
    };
    
    result = s1 + "\n" + s2 + "\n" + s3 + "\n" + s4 + "\n" + s5 + "\n" + s6 + "\n" + s7 + s8 + s9 + s10;
    return result;
}

