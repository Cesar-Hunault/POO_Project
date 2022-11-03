#ifndef RESULTATMEDECIN_H
#define RESULTATMEDECIN_H

#include <iostream>
#include <string>
#include <vector>
#include "cliche.h"

using namespace std;

class MedecinResult {

    private:
        vector<Cliche> liste;
        string cr_medecin;

    public: 
        MedecinResult(Cliche &c, string cr){
            this->liste.push_back(c);
            this->cr_medecin = cr;
        };

        void get_cliche(){
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                cliche.display();
            }
        };
        void set_cliche(const Cliche & c){
            liste.push_back(c);
        }

        void get_cr_medecin(){
            cout << "Doctor report : "<<this->cr_medecin<<endl;
        };
        void set_cr_medecin(string cr){
            this->cr_medecin = cr;
        };


        void medecin_result_display(){
            get_cliche();
            get_cr_medecin();
        };

};

#endif