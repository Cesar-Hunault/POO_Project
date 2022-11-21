#include <iostream>
#include <string>
#include <vector>
#include "patient.h"
#include "radiographie.h"

using namespace std;

void Patient::patient_display(){
    this->get_id();
    this->get_name();
    this->get_first_name();
    this->get_birth_date();
    this->get_gender();
}


void Patient::load_result(vector<Radiographie> &vecrad){


    for (int i=0; i<vecrad.size(); i++){
        if (vecrad[i].get_patient_id() == this->get_id_info()){

            this->resultats.push_back(&vecrad[i]);
            cout<<"trouvé"<<endl;
        }
    }
}

void Patient::result_display(){

    for (int i = 0; i<this->resultats.size(); ++i){
        cout<<"Result for radiography n°"<<resultats[i]->get_num_exam_info()<<endl;
        resultats[i]->get_date();
        resultats[i]->get_state();

        if (resultats[i]->get_state_info()==true){
            resultats[i]->get_pat_result();
        } else {
            cout<<"No result at the moment!"<<endl;
        }
    }
}
