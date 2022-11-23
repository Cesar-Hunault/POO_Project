#include <iostream>
#include <string>
#include <vector>
#include "patient.h"
#include "radiographie.h"

using namespace std;

// void Patient::patient_display(){
//     this->get_id();
//     this->get_name();
//     this->get_first_name();
//     this->get_birth_date();
//     this->get_gender();
// }

string Patient::patient_display(){
    
    string result;
    
    result += "Patient Id : "+this->get_id_info();
    result += "\nName : "+this->get_name_info();
    result += "\nFirst name : "+this->get_first_name_info();
    result += "\nBirth date : "+this->get_birth_date_info();
    result += "\nGender : "+this->get_gender_info();
    
    return result;
}

//Cherche les radiographies ayant le même patient_id que le patient, push_back dans la liste de résultats qui concernent le patient
void Patient::load_result(vector<Radiographie> &vecrad){

    for (int i=0; i<vecrad.size(); i++){
        if (vecrad[i].get_patient_id() == this->get_id_info()){
            this->resultats.push_back(&vecrad[i]);
        }
    }
}

//Affichage des resultats, radio par radio, avec la date et l'état, un message d'information si la radiographie n'a pas encore été faite
void Patient::result_display(){

    for (int i = 0; i<this->resultats.size(); ++i){
        cout<<"\n\tResult for radiography n°"<<resultats[i]->get_num_exam_info()<<"\n"<<endl;
        resultats[i]->get_date();
        resultats[i]->get_state();

        if (resultats[i]->get_state_info()==true){
            cout<<"\n"<<endl;
            resultats[i]->get_pat_result();
        } else {
            cout<<"\nNo result at the moment!\n"<<endl;
        }
    }
}
