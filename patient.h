#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "utilisateur.h"
#include "resultatPatient.h"

using namespace std;

class Patient : public Utilisateur{
    private:
        string birth_date;
        string gender;

        vector<PatientResult *> resultats;  //association unidirectionnelle

    public:

        Patient(string birth, string gen, string n, string f, string p) : Utilisateur(n, f, p){
            this -> birth_date = birth;
            this -> gender = gen;
        }

        void get_birth_date(){
            cout<< "Birth date : "<< this ->birth_date<<endl;
        }
        void set_birth_date(string birth){
            this -> birth_date = birth;
        }
        
        void get_gender(){
            cout<< "Gender : "<< this ->gender<<endl;
        }
        void set_gender(string gen){
            this -> gender = gen;
        }         

        void patient_display();

        void add_result(PatientResult&); //pas sensé être dans la classe patient, plus radiologue

        void result_display();
};

#endif