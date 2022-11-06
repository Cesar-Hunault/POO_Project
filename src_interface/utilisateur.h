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

        string get_name(){
            return this->name;
        };
        void set_name(string n){
            this->name = n;
        };
        
        string get_first_name(){
            return this-> first_name;
        };
        void set_first_name(string f){
            this->first_name = f;
        };

        string get_password(){
            return this->password;
        };
        void set_password(string p){
            this -> password = p;
        };
        
        
        string utilisateur_display();
        // void login();
        // void load();
};

#endif