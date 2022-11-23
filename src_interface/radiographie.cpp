#include <iostream>
#include <string>
#include "radiographie.h"

using namespace std;

// //Affichage classique
// void Radiographie::radiographie_display(){
//     this->get_num_exam();
//     this->get_type();
//     this->get_patient();
//     this->get_id_medecin();
//     this->get_date();
//     if (this->state){
//         cout << "State : radiography is performed"<<endl;
        
//         if (this->med_result != NULL){
//             cout << "\tDoctor report :"<<endl;
//             get_med_result();
//         };
//         if (this->pat_result != NULL){
//             cout << "\tPatient report :"<<endl;
//             get_pat_result();
//         };
        
//     }else{
//         cout << "State : radiography is planned"<<endl;
//     };
    
// }


string Radiographie::radiographie_display(){
    string result;
    result += "Radiography Id : "+this->get_num_exam_info();
    result += "\nType of radiography : "+this->get_type_info();
    result += "\n\tPatient : \n"+this->patient->patient_display();
    result += "\nDoctor Id : "+this->get_id_medecin_info();
    result += "\nDate : "+this->get_date_info();
    if (this->state){
        result += "\nState : radiography is performed\n";
        
        if (this->med_result != NULL){
            result += "\n\tDoctor report :\n";
            result += this->med_result->medecin_result_display();
        };
        if (this->pat_result != NULL){
            result += "\n\tPatient report :\n";
            result += this->pat_result->patient_result_display();
        };
        
    }else{
        result += "\nState : radiography is planned\n";
    };
    
    return result;
}
