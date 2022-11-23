#ifndef RADIOGRAPHIE_H
#define RADIOGRAPHIE_H

#include <string>
#include <iostream>
#include "patient.h"
#include "cliche.h"
#include "resultatMedecin.h"
#include "resultatPatient.h"

using namespace std;

class Radiographie{

    private:
        string num_examen;
        string type;

        Patient *patient;   //pointeur car aggrégation
        
        string id_medecin;
        string date;
        bool state;
        
        MedecinResult *med_result;
        PatientResult *pat_result;

    public:
        //Constructeurs ------------------------------------
        Radiographie(){};

        Radiographie(string num_exam, string type, Patient *patient,string id_med, string date, bool state){
            this->num_examen = num_exam;
            this->type = type;

            this->patient = patient;

            this->id_medecin = id_med;
            this->date = date;
            this->state = state;

            this->med_result = NULL;    //NULL car pas forcément de compte rendu si la radio est pas encore faite
            this->pat_result = NULL;
        };
        
        //Constructeur de recopie
        Radiographie(const Radiographie &r){
            this->num_examen = r.num_examen;
            this->type = r.type;
            this->patient = r.patient;
            this->id_medecin = r.id_medecin;
            this->date = r.date;
            this->state = r.state;
            this->med_result = r.med_result;
            this->pat_result = r.pat_result;
        };


        //geteurs et seteurs ------------------------------------
        void get_num_exam(){
            cout << "ID Radiography : "<<this->num_examen<<endl;
        };
        string get_num_exam_info(){ 
            return this->num_examen;
        };
        void set_num_exam(string num){
            this->num_examen = num;
        };


        void get_type(){
            cout << "Radiography type : "<<this->type<<endl;
        };
        string get_type_info(){
            return this->type;
        };
        void set_type(string type){
            this->type = type;
        };


        void get_patient(){
            this->patient->patient_display();
        };
        void set_patient(Patient *patient){
            this->patient = patient;
        };
        string get_patient_id(){
            return this->patient->get_id_info();
        };


        void get_id_medecin(){
            cout << "ID doctor : "<<this->id_medecin<<endl;
        };
        string get_id_medecin_info(){ 
            return this->id_medecin;
        };
        void set_id_medecin(string id){
            this->id_medecin = id;
        };


        void get_date(){
            cout << "Radiography date : "<<this->date<<endl;
        };
        string get_date_info(){
            return this->date;
        };
        void set_date(string date){
            this->date = date;
        };


        void get_state(){
            if (this->state){
                cout << "State : radiography is performed"<<endl;
            }else{
                cout << "State : radiography is planned"<<endl;
            };
        };
        bool get_state_info(){
            return this->state;
        };
        void set_state(bool state){
            this->state= state;
        };


        void get_med_result(){
            this->med_result->medecin_result_display();
        };
        string get_med_result_info(){
            string result;
            result += "\n"+this->med_result->get_cliche_info();
            result += this->med_result->get_cr_medecin_info();
            return result;
        };
        void set_med_result(MedecinResult *med){
            this->med_result = med;
        };


        void get_pat_result(){
            this->pat_result->patient_result_display();
        };
        void set_pat_result(PatientResult *pat){
            this->pat_result = pat;
        };
        string get_pat_result_info(){
            string result;
            result += this->pat_result->get_cliche_info();
            result += this->pat_result->get_cr_patient_info();
            return result;
        };


        string radiographie_display();
};

#endif