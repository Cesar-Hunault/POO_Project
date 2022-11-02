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


        void get_image(){
            cout << "Image is "<<this->image<<endl;
        };
        void set_image(string img){
            this->image = img;
        };


        void get_num_prise(){
            cout << "Num prise is "<<this->num_prise<<endl;
        };
        void set_num_prise(int num){
            this->num_prise = num;
        };


        void display(){
            get_image();
            get_num_prise();
        };
};