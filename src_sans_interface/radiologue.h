#ifndef RADIOLOGUE_H
#define RADIOLOGUE_H

#include <vector>
#include <tuple>
#include "radiographie.h"

using namespace std;

class Radiologue{

    private:
        int id_medecin;
        vector<Radiographie *> list;

    public:

        Radiologue(int id){
            this -> id_medecin = id;
        }

        void get_id_medecin(){
            cout<< "Doctor ID :" << this->id_medecin<<endl;
        }
        int set_id_medecin(int id){
            return this->id_medecin = id;
        }

        Radiographie * get_rad_in_list(int i){
            return this->list[i];
        }
        void clear_list(){
            this->list.clear();
        }

        void add_radio_in_list(Radiographie &);
        void radio_list_display();

        tuple<Radiographie, Patient, string> add_new_radio(int , int, vector<Patient>&);

        void delete_radio(string, vector<Radiographie> &);
        Radiographie modify_radio(Radiographie &);
        
        void save_new_patient(Patient &);
        void save_new_radio(Radiographie &);
        void save_all_radio(vector<Radiographie> &);
        void save_all_patients(vector<Patient> &);


};

#endif