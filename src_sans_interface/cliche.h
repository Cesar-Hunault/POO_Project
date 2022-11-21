#ifndef CLICHE_H
#define CLICHE_H

#include <iostream>
#include <string>

using namespace std;

class Cliche{

    private:
        string image;
        string num_prise;

    public:
        //Constructeur ------------------------------------
        Cliche(string img, string num){
            this->image = img;
            this->num_prise = num;
        };


        //geteurs et seteurs ------------------------------------
        void get_image(){
            cout << "Image is "<<this->image<<endl;
        };
        string get_image_info(){
            return this->image;
        };
        void set_image(string img){
            this->image = img;
        };


        void get_num_prise(){
            cout << "Num prise is "<<this->num_prise<<endl;
        };
        string get_num_prise_info(){
            return this->num_prise;
        };
        void set_num_prise(string num){
            this->num_prise = num;
        };


        void display(){
            get_image();
            get_num_prise();
        };
        string display_info(){
            string result;
            result += this->get_image_info();
            result += "\n"+this->get_num_prise_info()+"\n";

            return result;
        };
};

#endif