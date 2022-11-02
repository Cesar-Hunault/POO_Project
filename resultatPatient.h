#ifndef RESULTATPATIENT_H
#define RESULTATPATIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "cliche.h"

using namespace std;

class PatientResult {

    private:
        vector<Cliche> liste;
        string cr_patient;

    public: 
        PatientResult(Cliche &c, string cr){
            this->liste.push_back(c);
            this->cr_patient = cr;
        };

        void get_cliche(){
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                cliche.display();
            }
        };

        void set_cliche(const Cliche & c){
            liste.push_back(c);
        }

        void get_cr_patient(){
            cout << "Patient report : "<<this->cr_patient<<endl;
        };
        void set_cr_patient(string cr){
            this->cr_patient = cr;
        };


        void patient_result_display(){
            get_cliche();
            get_cr_patient();
        };

};

#endif