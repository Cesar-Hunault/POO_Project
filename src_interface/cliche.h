#ifndef CLICHE_H
#define CLICHE_H

#include <iostream>
#include <string>

using namespace std;

class Cliche{

    private:
        string image;
        int num_prise;

    public:
        Cliche(string img, int num){
            this->image = img;
            this->num_prise = num;
        };


        string get_image(){
           return this->image;
        };
        void set_image(string img){
            this->image = img;
        };


        int get_num_prise(){
           return this->num_prise;
        };
        void set_num_prise(int num){
            this->num_prise = num;
        };


        string display(){
            string s1, s2, result;
            s1 = this->get_image();
            s2 = this->get_num_prise();
            result = s1 + "\n" + s2 + "\n";
            return result;
        };
};

#endif