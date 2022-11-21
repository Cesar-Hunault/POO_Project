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

        vector<Radiographie *> resultats;  //association unidirectionnelle

    public:
        //Constructeurs ------------------------------------
        Patient(){};
        
        Patient(string i, string p, string na, string fna, string birth, string gen) : Utilisateur(i, p){
            this -> name = na;
            this -> first_name = fna;
            this -> birth_date = birth;
            this -> gender = gen;
        };

        //Constructueur de recopie
        Patient(const Patient &p) : Utilisateur(p){
            this -> name = p.name;
            this -> first_name = p.first_name;
            this -> birth_date = p.birth_date;
            this -> gender = p.gender;
        };

        //geteurs et seteurs ------------------------------------
        void get_name(){
            cout<< "Name : "<< this-> name<<endl;
        };
        string get_name_info(){
            return this-> name;
        };
        void set_name(string na){
            this -> name = na;
        };


        void get_first_name(){
            cout<< "First name : "<< this-> first_name<<endl;
        };
        string get_first_name_info(){
            return this-> first_name;
        };
        void set_first_name(string fna){
            this -> first_name = fna;
        };


        void get_birth_date(){
            cout<< "Birth date : "<< this ->birth_date<<endl;
        };
        string get_birth_date_info(){
            return this ->birth_date;
        };
        void set_birth_date(string birth){
            this -> birth_date = birth;
        };

        
        void get_gender(){
            cout<< "Gender : "<< this ->gender<<endl;
        };
        string get_gender_info(){
            return this ->gender;
        };
        void set_gender(string gen){
            this -> gender = gen;
        }; 


        void patient_display();

        void load_result(vector<Radiographie>&);
        void result_display();
};

#endif