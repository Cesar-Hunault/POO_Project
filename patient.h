#include <string>
#include "utilisateur.h"

using namespace std;

class Patient : public Utilisateur{
    private:
        string birth_date;
        string gender;

    public:

        Patient(string birth, string gen, string n, string f, string p) : Utilisateur(n, f, p){
            this -> birth_date = birth;
            this -> gender = gen;
        }

        void get_birth_date(){
            cout<< "Birth date is "<< this ->birth_date<<endl;
        }
        void set_birth_date(string birth){
            this -> birth_date = birth;
        }
        
        void get_gender(){
            cout<< "Gender is "<< this ->gender<<endl;
        }
        void set_gender(string gen){
            this -> gender = gen;
        }         

        void display();
};