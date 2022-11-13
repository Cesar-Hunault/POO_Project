#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "utilisateur.h"
#include "resultatPatient.h"

using namespace std;

class Patient : public Utilisateur{
    private:
        string name;
        string first_name;
        string birth_date;
        string gender;

        vector<PatientResult *> resultats;  //association unidirectionnelle

    public:

        Patient(string i, string p, string na, string fna, string birth, string gen) : Utilisateur(i, p){
            this -> name = na;
            this -> first_name = fna;
            this -> birth_date = birth;
            this -> gender = gen;
        }

        Patient(const Patient &p) : Utilisateur(p){
            this -> birth_date = p.birth_date;
            this -> gender = p.gender;
        }

        string get_name(){
            return this-> name;
        }
        void set_name(string na){
            this -> name = na;
        }

        string get_first_name(){
            return this-> first_name;
        }
        void set_first_name(string fna){
            this -> first_name = fna;
        }

        string get_birth_date(){
            return this-> birth_date;
        }
        void set_birth_date(string birth){
            this -> birth_date = birth;
        }
        
        string get_gender(){
           return this-> gender;
        }
        void set_gender(string gen){
            this -> gender = gen;
        }         

        string patient_display();

        void add_result(PatientResult&); //pas sensé être dans la classe patient, plus radiologue

        void result_display();
};

#endif