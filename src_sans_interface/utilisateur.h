#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <vector>

using namespace std;

//Forward déclaration pour charger les bases de données
class Patient;
class Radiographie;
class MedecinResult;
class PatientResult;

class Utilisateur {
    protected: //protected pour l'héritage de patient et radiologue 
        string id;
        string password;
    
    public:
        //Constructeurs ------------------------------------
        Utilisateur(){}
        Utilisateur(string i, string p){
            this->id = i;
            this->password = p; 
        };

        //geteurs et seteurs ------------------------------------
        //deux types de geteurs dans tous les fichiers suivant :  les get_varaible() qui présentent la donnée avec un texte, utilisés dans les fonctions d'affichage essentiellement, et les get_variable_info() qui return directement la variable seule utilisées pour traiter les informations.

        void get_id(){
            cout << "Id : " <<  this->id<<endl;
        };
        string get_id_info(){ //utilisé dans utilisateur::load_radiography()
            return this->id;
        };
        void set_id(string i){
            this->id = i;
        };


        void get_password(){
            cout << "Password : " << this->password <<endl;
        };
        string get_password_info(){
            return this->password;
        };
        void set_password(string p){
            this -> password = p;
        };
        
        
        //Fonctions autre ---------------------------------------
        void utilisateur_display();

        pair<bool, bool> login();
        vector<Patient> load_patient();
        tuple<vector<Radiographie>, vector<MedecinResult>, vector<PatientResult>, vector<int>> load_radiography(vector<Patient> &);
        void add_new_patient_in_login(Patient &);
};

#endif