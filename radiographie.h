#include <string>
#include <iostream>
#include "patient.h"

using namespace std;

class Radiographie{

    private:
        int num_examen;
        string type;

        Patient *patient;
        
        string id_medecin;
        string date;
        bool state;
        // RESULTAT MEDECIN
        // RESULTAT PATIENT

    public:
        Radiographie(int num_exam, string type, Patient *id_patient,string id_med, string date, bool state){
            this->num_examen = num_exam;
            this->type = type;

            this->patient = id_patient;

            this->id_medecin = id_med;
            this->date = date;
            this->state = state;
        };
        

        void get_num_exam(){
            cout << "Num exam is "<<this->num_examen<<endl;
        };
        void set_num_exam(int num){
            this->num_examen = num;
        };


        void get_type(){
            cout << "Radiography type is "<<this->type<<endl;
        };
        void set_type(string type){
            this->type = type;
        };


        void get_patient(){
            this->patient->display();
        }
        void set_patient(Patient *patient){
            this->patient = patient;
        }


        void get_id_medecin(){
            cout << "Medecin ID is "<<this->id_medecin<<endl;
        };
        void set_id_medecin(int id){
            this->id_medecin = id;
        };


        void get_date(){
            cout << "Radiography date is "<<this->date<<endl;
        };
        void set_date(int date){
            this->date = date;
        };


        void get_state(){
            if (this->state){
                cout << "State : radiography is performed"<<endl;
            }else{
                cout << "State : radiography is planned"<<endl;
            };
        };
        void set_state(bool state){
            this->state= state;
        };


        void display();
};
