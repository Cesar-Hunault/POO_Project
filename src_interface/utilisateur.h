#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>

using namespace std;

class Utilisateur {
    protected:
        string id;
        string password;
    
    public:
    
        Utilisateur(string i, string p){
            this->id = i;
            this->password = p; 
        };

        string get_id(){
            return this->id;
        };
        void set_id(string i){
            this->id = i;
        };
        
        string get_password(){
            return this->password;
        };
        void set_password(string p){
            this -> password = p;
        };
        
        
        string utilisateur_display();
        pair<bool, bool> login(string, string);
        // void load();
};

#endif