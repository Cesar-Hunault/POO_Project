#include <iostream>
#include <vector>
#include <string>
#include "radiologue.h"
#include "radiographie.h"

using namespace std;

void Radiologue::add_radio_in_list(Radiographie &radio){
    this->list.push_back(&radio);
};

void Radiologue::radio_list_display(){
    for (int i = 0; i < this->list.size(); ++i){
        Radiographie item_list = *this->list[i];
        cout<<"\n############### Radiographie n°"<<i+1<<" ###############"<<endl;
        item_list.radiographie_display();
    }
};

tuple<Radiographie, Patient> Radiologue::add_new_radio(){

    int compteur_identifiant;//bloqué
    string type;
    string new_patient;
    string name;
    string first_name;
    string password ="mdp bien trop faible";
    string birth_date;
    string gender;
    string med_id;
    string rad_date;
    bool state=false;

    cout <<"Type of radiography :"<<endl;
    cin>>type;
    // cout <<"New patient ? (1 for new, 0 for existant)"<<endl;
    // cin>>new_patient;

   //if (new_patient=="1"){
        cout << "Name : " <<endl;
        cin>>name;
        cout << "First name : " <<endl;
        cin>>first_name;
        //password à modifier puisque pas à demander ici
        cout<< "Birth date : "<<endl;
        cin>>birth_date;
        cout<< "Gender : "<<endl;
        cin>>gender;
    //}
    // if (new_patient=="0"){
    //     //a faire la liaison avec un patient existant, peut être grace à l'interface, avec l'affichage de la liste des patients ??
    // }

    Patient *ptr_patient= new Patient(name, first_name, password, birth_date, gender);

    cout<<"Doctor Id :"<<endl;
    cin>>med_id;
    cout<<"Date of the radiography :"<<endl;
    cin>>rad_date;

    Radiographie *ptr_nouvelle_radio = new Radiographie(99, type, ptr_patient, med_id, rad_date, state);
    cout<<"\n############### Recap ###############"<<endl;
    ptr_nouvelle_radio->radiographie_display();

    //Utilisation des constructeurs de recopie de Patient et Radiographie pour les créer en profondeur et pouvoir les récupérer à la fin de la fonction sans qu'ils ne soient détruits
    Patient vrai_patient(*ptr_patient);
    Radiographie vrai_nouvelle_radio(*ptr_nouvelle_radio);

    //NE MARCHE PAS, OBLIGÉ DE LE FAIRE À L'EXTERIEUR
    // add_radio_in_list(vrai_nouvelle_radio);

    // //delete new radiographie et new patient car rien ne les détruits
    // delete ptr_nouvelle_radio;
    // delete ptr_patient;
    //NE MARCHE PLUS QUAND LES POINTEURS SONT DELETE JE SAIS PAS POURQUOI

    return make_tuple(vrai_nouvelle_radio, vrai_patient);

}

void Radiologue::delete_radio(int id_radio){
    for (auto i = this->list.begin(); i != this->list.end();){

        if ((*i)->get_num_exam() ==id_radio){       //syntaxe pour obtenir accès à la méthode par l'itérateur : https://stackoverflow.com/questions/63369486/c-cant-access-a-public-attribute-in-a-class-that-is-returned-by-the-vectors
            i = this->list.erase(i);
        } else {
            i++;
        }
    }
}   
