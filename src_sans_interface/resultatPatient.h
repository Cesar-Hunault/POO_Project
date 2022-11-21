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
        PatientResult(){}

        PatientResult(Cliche &c, string cr){
            this->liste.push_back(c);
            this->cr_patient = cr;
        };
        
        PatientResult(const PatientResult &p){
            this->liste = p.liste;
            this->cr_patient = p.cr_patient; 
        }

        void get_cliche(){
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                cliche.display();
            }
        };
        string get_cliche_info(){
            string result;
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                result += cliche.display_info();
            }
            return result;
        };

        void set_cliche(const Cliche & c){
            liste.push_back(c);
        }

        void get_cr_patient(){
            cout << "Patient report : "<<this->cr_patient<<endl;
        };
        string get_cr_patient_info(){
            return this->cr_patient;
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