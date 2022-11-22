#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "string.h"
#include "radiologue.h"
#include "radiographie.h"

using namespace std;

//Ajout d'une radio dans la liste du radiologue, permet l'affichage qui suit
void Radiologue::add_radio_in_list(Radiographie &radio){
    this->list.push_back(&radio);
};

//Affichage des radio présentes dans la liste du radiologue 
void Radiologue::radio_list_display(){
    for (int i = 0; i < this->list.size(); ++i){
        Radiographie item_list = *this->list[i];
        cout<<"\n############### Radiographie n°"<<i+1<<" ###############"<<endl;
        item_list.radiographie_display();
    }
};

//Ajout d'une radio dans la base de données
tuple<Radiographie, Patient, string> Radiologue::add_new_radio(int last_patient_id, int last_radio_id, vector<Patient> &vecpat){

    //Variables liées à la création ou non d'un nouveau patient
    string new_patient;
    string id_patient;
    string name;
    string first_name;
    string password;
    string birth_date;
    string gender;
    Patient *ptr_patient=NULL;

    //Variables liées à la création d'une nouvelle radiographie
    string radio_type;
    int type;
    string med_id;
    string rad_date;
    string num_examen;
    bool state=false;

    //Formulaire d'ajout
    cout <<"New patient ? \n\t1 for new \n\t0 for existant"<<endl;
    cin>>new_patient;

    if (new_patient=="1"){
        id_patient = to_string(last_patient_id+1); //Augmente de 1 par rapport à l'id max présent dans la base de données
        cout<<id_patient<<endl;

        cout << "Name : " <<endl;
        cin>>name;
        cout << "First name : " <<endl;
        cin>>first_name;
        cout<< "Birth date : jj/mm/aaaa"<<endl;
        cin>>birth_date;
        cout<< "Gender : Male/Female"<<endl;
        cin>>gender;
        cout<< "Assign a password"<<endl;
        cin>>password;
        
        ptr_patient= new Patient(id_patient, password, name, first_name, birth_date, gender); //Initialisation du nouveau patient 
        
    }
    if (new_patient=="0"){
        cout<<"Patient ID :"<<endl;
        cin>>id_patient;

        for(int i=0; i<vecpat.size(); i++){
            if (vecpat[i].get_id_info()==id_patient){
            ptr_patient = &vecpat[i];   //Récupération de l'adresse du patient existant
            }
        }
        if (ptr_patient==NULL){
            cout<<"The patient was not found"<<endl;
            exit(1);
        }
    }

    cout <<"\nType of radiography :\n\t1: Xray\n\t2: Ultrasound\n\t3: MRI"<<endl;
    cin>>type;
    switch (type)
    {
    case 1:
        radio_type="Xray";
        break;
    case 2:
        radio_type="Ultrasound";
        break;
    case 3:
        radio_type="MRI";
        break;
    
    default:
        cout<<"Bad choice!"<<endl;
        break;
    }

    med_id = this->id;  

    cout<<"Date of radiography : jj/mm/aaaa"<<endl;
    cin>>rad_date;

    num_examen = to_string(last_radio_id+1);  //Augmente de 1 par rapport à l'id max présent dans la base de données

    Radiographie *ptr_nouvelle_radio = new Radiographie(num_examen, radio_type, ptr_patient, med_id, rad_date, state);  //Initialisation de la nouvelle radiographie

    cout<<"\n############### Recap ###############"<<endl;
    ptr_nouvelle_radio->radiographie_display(); // -> au lieu de . pour acceder à la méthode quand c'est un pointeur vers un objet

    //Utilisation des constructeurs de recopie de Patient et Radiographie pour les créer en profondeur et pouvoir les récupérer à la fin de la fonction sans qu'ils ne soient détruits
    Patient return_patient(*ptr_patient);
    Radiographie return_radio(*ptr_nouvelle_radio);

    // // //delete new radiographie et new patient car rien ne les détruits
    // // delete ptr_nouvelle_radio;
    // // delete ptr_patient;
    // //NE MARCHE PLUS QUAND LES POINTEURS SONT DELETE JE SAIS PAS POURQUOI

    return make_tuple(return_radio, return_patient, new_patient); //return new_patient pour savoir facilement si le patient est un nouveau ou non

}

//Suppression d'une radio
void Radiologue::delete_radio(string id_radio, vector<Radiographie> &vecrad){

    bool trouve = false;

    for (auto i = vecrad.begin(); i != vecrad.end();){
    
        if ((*i).get_num_exam_info() ==id_radio){       //syntaxe pour obtenir accès à la méthode par l'itérateur : https://stackoverflow.com/questions/63369486/c-cant-access-a-public-attribute-in-a-class-that-is-returned-by-the-vectors
            i = vecrad.erase(i);
            trouve = true;
        } else {
            i++;
        }
    }

    if(!trouve){
        cout<<"Radiographie non trouvée !";
    }
}   

//Modification d'une radio
Radiographie Radiologue::modify_radio(Radiographie &radiographie){

    int choice;

    Cliche *ptr_cliche;
    vector<Cliche *> ptr_vec_cliche;

    MedecinResult *ptr_med_res;
    PatientResult *ptr_pat_res;

    int nbr_radio;

    string img, num_prise, med_report, pat_report;

    do
    {
        cout<<"\n############### Recap ###############"<<endl;   //recap des valeurs de la radio à modifier, se met à jour à chaque fois qu'une modification a été faite puisque présent dans le do{}
        radiographie.radiographie_display();

        cout<<"\nQue voulez vous modifier :"<<endl; //possible de modifier seulement ces trois paramètres, pas le patient ni les num d'examents et id_medecin
        cout<<"1 -\tType de radiographie"<<endl;
        cout<<"2 -\tDate de la radiographie"<<endl;
        cout<<"3 -\tEtat de la radiographie"<<endl;
        cout<<"4 -\tQuitter!"<<endl;

        cin>>choice;

        switch (choice)
        {
        case 1:
            {   
                int type;
                string radio_type;

                cout <<"\nSelect :\n\t1: Xray\n\t2: Ultrasound\n\t3: MRI"<<endl;
                cin>>type;

                switch (type)
                {
                case 1:
                    radio_type="Xray";
                    break;
                case 2:
                    radio_type="Ultrasound";
                    break;
                case 3:
                    radio_type="MRI";
                    break;
                
                default:
                    cout<<"Bad choice!"<<endl;
                    break;
                }

                radiographie.set_type(radio_type);
                break;
            }
        
        case 2:
            {
                string date;

                cout<<"Entrez la nouvelle date :"<<endl;
                cin>>date;

                radiographie.set_date(date);
                break;
            }

        case 3:
            {
                int str_state;
                bool state;

                cout<<"Entrez l'état de la radiographie :\n\t1: Planned\n\t2: Performed"<<endl;
                cin>>str_state;

                switch (str_state)
                {
                case 1: 
                    //Vérrification du state précédent, si il était deja réalisé, suppression des resultats medecin et patient et initialisation du state à prévu
                    if (radiographie.get_state_info()){
                        radiographie.set_med_result(NULL);
                        radiographie.set_pat_result(NULL);
                    }
                    state = false;

                    radiographie.set_state(state);

                    break;
                
                case 2:     //Nécéssite de mettre à jour les resultats medecin et patient
                    { 
                        state = true;
                        radiographie.set_state(state);

                        cout<<"Completez les resultats : \n\tNombre de radiographies à ajouter :"<<endl;
                        cin>>nbr_radio;
                        cin.ignore(1, '\n'); //enleve le retour charriot laissé par le cin pour utiliser convenablement les getlines suivant.

                        //Initialisation des cllichés
                        for(int i=1; i<=nbr_radio; i++){
                            cout<<"Liez une radiographie (exemple : 'image x'):"<<endl;
                            getline (cin, img);//permet de récuperer les espaces
                            cout<<"Quel est son numéro de prise (exemple : '1'):"<<endl;
                            getline (cin, num_prise);

                            ptr_cliche = new Cliche(img, num_prise);
                            ptr_vec_cliche.push_back(ptr_cliche);
                        }

                        //Initialisation des deux rapports 
                        cout<<"Rapport medecin"<<endl;
                        getline (cin, med_report);
                        cout<<"Rapport patient"<<endl;
                        getline (cin, pat_report);

                        //Création de deux objets resultats à l'aide de leur constructeur vide
                        ptr_med_res = new MedecinResult();
                        ptr_pat_res = new PatientResult();

                        //Ajout des clichés dans les deux resultats
                        for (int i=0; i<ptr_vec_cliche.size(); i++){
                            ptr_med_res->set_cliche(*ptr_vec_cliche[i]);
                            ptr_pat_res->set_cliche(*ptr_vec_cliche[i]);
                        }

                        //Ajout des rapports
                        ptr_med_res->set_cr_medecin(med_report);
                        ptr_pat_res->set_cr_patient(pat_report);

                        //Ajout des resultats complets dans la radiographie modifiée
                        radiographie.set_med_result(ptr_med_res);
                        radiographie.set_pat_result(ptr_pat_res);

                        break;
                    }
                
                default:
                    cout<<"Bad choice"<<endl;
                    break;
                }            
            }
        default:
            break;
        }

    } while (choice !=  4);
    
    return (radiographie);

}



//Sauvegarde d'un nouveau patient, sans réécrire par dessus la base de données
void Radiologue::save_new_patient(Patient &patient){

    ofstream file1("BD_patient.txt", ofstream::app); 

    //6 arguments obligatoirement donc ecriture rapide
    file1 << patient.get_id_info() <<'\n' << patient.get_password_info() << '\n' << patient.get_name_info() << '\n' << patient.get_first_name_info() << '\n' << patient.get_birth_date_info() << '\n' << patient.get_gender_info()<< '\n';

    file1.close();
}

//Sauvegarde d'une nouvelle radiographie, sans réécrire par dessus la base de données
void Radiologue::save_new_radio(Radiographie &radiographie){

    ofstream file2("BD_radiographies.txt",  ofstream::app);

    //Vérification du state de la radiographie pour savoir si les resultats sont présents et doivent être écris ou non
    file2 << radiographie.get_num_exam_info() <<'\n'<< radiographie.get_type_info() <<'\n'<< radiographie.get_patient_id() <<'\n'<< radiographie.get_id_medecin_info() <<'\n'<< radiographie.get_date_info() <<'\n'<< radiographie.get_state_info();
    if (radiographie.get_state_info()){
        file2<< radiographie.get_med_result_info() <<'\n'<< radiographie.get_pat_result_info()<<'\n';
    } else {
        file2<<'\n';
    }
    file2<< "}\n"; //Ajout du séparateur à la fin

    file2.close();
}

//Sauvegarde de toutes les radio présentes dans le vecteur, en réécrivant la base de données
void Radiologue::save_all_radio(vector<Radiographie> &vecrad){

    ofstream file2("BD_radiographies.txt");

    for (int i=0; i<vecrad.size(); i++){

        file2 << vecrad[i].get_num_exam_info() <<'\n'<< vecrad[i].get_type_info() <<'\n'<< vecrad[i].get_patient_id() <<'\n'<< vecrad[i].get_id_medecin_info() <<'\n'<< vecrad[i].get_date_info() <<'\n'<< vecrad[i].get_state_info();
        if (vecrad[i].get_state_info()){
            file2<< vecrad[i].get_med_result_info() <<'\n'<< vecrad[i].get_pat_result_info()<<'\n';
        } else {
            file2<<'\n';
        }
        file2<< "}\n";
    }

    file2.close();
}

//Sauvegarde de tous les patients présents dans le vecteur, en réécrivant la base de données
void Radiologue::save_all_patients(vector<Patient> &vecpat){
    
    ofstream file1("BD_patient.txt"); 
    
    for (int i=0; i<vecpat.size(); i++){
        file1 << vecpat[i].get_id_info() <<'\n' << vecpat[i].get_password_info() << '\n' << vecpat[i].get_name_info() << '\n' << vecpat[i].get_first_name_info() << '\n' << vecpat[i].get_birth_date_info() << '\n' << vecpat[i].get_gender_info()<< '\n';
    }
    
    file1.close();
}


bool Radiologue::switch_verification(string user_input, int choice){
    
    const char *char_user_input = user_input.c_str();

    bool verification = false;
    string return_user_input;
    if (strlen(char_user_input) > 2){
        cout<<"Invalid strlen()"<<endl;
        return verification;
    }

    if (sscanf(char_user_input, "%d", &choice) != 1){
        cout<<"Invalid sscanf()"<<endl;
        return verification;
    }

    verification = true;
    return verification;

}