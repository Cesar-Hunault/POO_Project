#ifndef RADIOLOGUE_H
#define RADIOLOGUE_H

#include <vector>
#include <tuple>
#include "radiographie.h"

using namespace std;

class Radiologue : public Utilisateur{

    private:
        
        vector<Radiographie *> list;

    public:
        //Constructeur ------------------------------------
        Radiologue(){};
        Radiologue(string i, string p): Utilisateur(i, p){
        };

        //geteurs et seteurs ------------------------------------
        void get_id_medecin(){
            cout<< "Doctor ID :" << this->id<<endl;
        };
        string get_id_medecin_info(){
            return this->id;
        };
        string set_id_medecin(string id){
            return this->id = id;
        };


        void get_password_medecin(){
            cout<<"Doctor password :" << this->password<<endl;
        }
        string set_password_medecin(string p){
            return this->password = p;
        };


        Radiographie * get_rad_in_list(int i){
            return this->list[i];
        };
        void add_radio_in_list(Radiographie &);


        void clear_list(){
            this->list.clear();
        };

        //Fonctions autre ---------------------------------------
        //Affichage de la liste de radio
        string radio_list_display();

        //Ajout d'une radio
        tuple<Radiographie, Patient, string> add_new_radio(int , int, vector<Patient>&);

        //Suppression d'une radio
        void delete_radio(string, vector<Radiographie> &);

        //Modification d'une radio
        Radiographie modify_radio(Radiographie &);
        
        //Sauvegarde des bases de données
        void save_new_patient(Patient &);
        void save_new_radio(Radiographie &);
        void save_all_radio(vector<Radiographie> &);
        void save_all_patients(vector<Patient> &);

        bool switch_verification(string, int);

};

#endif