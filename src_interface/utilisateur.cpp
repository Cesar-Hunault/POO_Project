#include <string>
#include <iostream>
#include <fstream>
#include "utilisateur.h"

using namespace std;

string Utilisateur::utilisateur_display(){
    string result1 = this->id;
    string result2 = this->password;
    string result3 = result1 + "\n" + result2;
    
    //this->get_password();
    // cout<<"Password protected"<<endl;
    return result3;

}

pair<bool, bool> Utilisateur::login(string id, string password){

    ifstream file("BD_login.txt");

    string line, id_verif, password_verif, med_verif;
    bool med = false, login_state = false;
    pair<bool, bool> login;

    while (getline(file, line))
    {
        if ( line[0]!='#' && line[0]!= '\n'){
            int sep = line.find(';');
            int sep2 = line.find('/');

            id_verif = line.substr(0, sep);
            password_verif = line.substr(sep+1, sep2-sep-1);
            med_verif = line.substr(sep2+1, line.length()-1);

            if (id == id_verif && password == password_verif){
                if (med_verif=="true"){
                    med = true;
                }

                login_state = true;

                login.first = login_state;
                login.second = med;
            }
        }
    }
    return login;
}
