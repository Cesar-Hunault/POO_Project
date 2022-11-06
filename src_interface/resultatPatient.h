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

        string get_cliche(){
            string result;
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                result += cliche.display();
            }
            return result;
        };

        void set_cliche(const Cliche & c){
            liste.push_back(c);
        }

        string get_cr_patient(){
            return this->cr_patient;
        };
        void set_cr_patient(string cr){
            this->cr_patient = cr;
        };


        string patient_result_display(){
            string s1, s2, result;
            s1 = this->get_cliche();
            s2 = "Report for patient : "+this->get_cr_patient();
            result = s1 + "\n" + s2 + "\n";
            return result;
        };

};

#endif