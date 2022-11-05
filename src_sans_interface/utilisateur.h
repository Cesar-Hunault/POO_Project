#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>

using namespace std;

class Utilisateur {
    protected:
        string name;
        string first_name;
        string password;
    
    public:
    
        Utilisateur(string n, string f, string p){
            this->name = n;
            this->first_name = f;
            this->password = p; 
        };

        void get_name(){
            cout << "Name : " << this->name <<endl;
        };
        void set_name(string n){
            this->name = n;
        };
        
        void get_first_name(){
            cout << "First name : " << this-> first_name <<endl;
        };
        void set_first_name(string f){
            this->first_name = f;
        };

        void get_password(){
            cout << "Password : " << this->password <<endl;
        };
        void set_password(string p){
            this -> password = p;
        };
        
        
        void utilisateur_display();
        // void login();
        // void load();
};

#endif