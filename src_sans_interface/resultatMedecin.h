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
        //Constructeurs ------------------------------------
        MedecinResult(){};

        MedecinResult(Cliche &c, string cr){
            this->liste.push_back(c);
            this->cr_medecin = cr;
        };

        MedecinResult(const MedecinResult &m){
            this->liste = m.liste;
            this->cr_medecin = m.cr_medecin;
        };


        //geteurs et seteurs ------------------------------------
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
        };


        void get_cr_medecin(){
            cout << "Doctor report : "<<this->cr_medecin<<endl;
        };
        string get_cr_medecin_info(){
            return this->cr_medecin;
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