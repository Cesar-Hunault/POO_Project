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

        string get_cliche(){
            string result;
            for (int i = 0; i < this->liste.size(); ++i){
                Cliche cliche = this->liste[i];
                result += cliche.display();
            }
            return result;
        };
        void set_cliche(const Cliche & c){
            liste.push_back(c);
        }

        string get_cr_medecin(){
            return this->cr_medecin;
        };
        void set_cr_medecin(string cr){
            this->cr_medecin = cr;
        };


        string medecin_result_display(){
            string s1, s2, result;
            s1 = this->get_cliche();
            s2 = "Doctor report : "+this->get_cr_medecin();
            result = s1 + "\n" + s2 + "\n";
            return result;
        };

};

#endif