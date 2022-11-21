#include <iostream>
#include <fstream>
#include "radiographie.h"
#include "radiologue.h"
// #include "resultatPatient.h"
// #include "resultatMedecin.h"


using namespace std;

int main () {

    //Login ----------------------------------------------------------------------------------
    string id, password;

    cout<<"ID :"<<endl;
    cin>>id;
    cout<<"Password :"<<endl;
    cin>>password;

    Utilisateur utilisateur(id, password);

    pair<bool, bool> log_pair;

    log_pair = utilisateur.login();

    cout<<log_pair.first<<"\t"<<log_pair.second<<endl;

    //Chargement des données -----------------------------------------------------------------------
    vector<Patient> vecpat;
    vector<Radiographie> vecrad;
    vector<MedecinResult> vec_med_res;
    vector<PatientResult> vec_pat_res;
    vector<int> liste_indice;

    vecpat = utilisateur.load_patient();
    tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

    //ajout des resultats medecins et patients à l'extérieur de la fonction load_radiography, ne marche pas à l'interieur -> pourquoi ??
    //On retiens les radio qui ont un resultat dans la liste d'indice pour les ajouter ici
    for(int h=0; h<liste_indice.size(); h++){
        vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
        vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
    }

    //Prise d'info des identifiants max présent dans les bases de données 
    int last_radio_id=-900, last_patient_id=-900; 

    for(int i=0; i<vecpat.size(); i++){
        if (stoi(vecpat[i].get_id_info())>last_patient_id){
            last_patient_id=stoi(vecpat[i].get_id_info());
        }
    }
    
    for(int j=0; j<vecrad.size(); j++){
        if (stoi(vecrad[j].get_num_exam_info())>last_radio_id){
            last_radio_id=stoi(vecrad[j].get_num_exam_info());
        }
    }

    if (log_pair.first == false){
        cout<<"login error!"<<endl;
    }

    //Page partie Patient ----------------------------------------------------------------------------------
    if (log_pair.first == true && log_pair.second == false){
        //Patient
        Patient patient;

        for (int i=0; i<vecpat.size(); i++){
            if (vecpat[i].get_id_info() == id){
                patient = vecpat[i];
            }
        }
        cout<<"\nHello "<<patient.get_first_name_info()<<endl;

        patient.load_result(vecrad);
        patient.result_display();
    }
    
    //Page partie Radiologue ----------------------------------------------------------------------------------
    if (log_pair.first == true && log_pair.second == true){
        //Radiologue
        cout<<"\nLog as a Radiologist"<<endl;
        cout<<"ID : "<<id<<endl;

        Radiologue radiologue(stoi(id));
                
        //Menu d'action --------------------------------------------
        int choice;
        do
        {
            cout<<"\n\nChoose an action :"<<endl;
            cout<<"1 -\tAfficher vos radiographies"<<endl;
            cout<<"2 -\tAjouter une radiographie"<<endl;
            cout<<"3 -\tSupprimer une radiographie"<<endl;
            cout<<"4 -\tModifier une radiographie"<<endl;
            cout<<"5 -\tSauvegarder les données"<<endl;
            cout<<"6 -\tRecharger les données"<<endl;
            cout<<"7 -\tQuitter!"<<endl;

            cin>>choice;

            switch (choice)
            {
            case 1:
                {//accolades pour pouvoir instancier des variables dans un case de switch
                    int display_choice;
                    do
                    {
                        cout<<"\n\nMode d'affichage :"<<endl;
                        cout<<"1 -\tAfficher toutes vos radiographies"<<endl;
                        cout<<"2 -\tChercher par numéro d'examen"<<endl;
                        cout<<"3 -\tChercher par identifiant de patient"<<endl;
                        cout<<"4 -\tChercher par date"<<endl;
                        cout<<"5 -\tQuitter"<<endl;
                        cin>>display_choice;
                        switch (display_choice)
                        {
                        case 1:
                            radiologue.clear_list(); //Nettoyage de la liste de radio dépendamment du filtre voulu, répété à chaque choix
                            for (int i=0; i<vecrad.size(); i++){
                                if(vecrad[i].get_id_medecin_info() == id){
                                    radiologue.add_radio_in_list(vecrad[i]);
                                }
                            }
                            radiologue.radio_list_display();
                        
                            break;

                        case 2:
                        {
                            string num_exam;
                            cout<<"Numéro d'examen :"<<endl;
                            cin>>num_exam;

                            radiologue.clear_list();
                            for (int i=0; i<vecrad.size(); i++){
                                if(vecrad[i].get_num_exam_info() == num_exam){
                                    radiologue.add_radio_in_list(vecrad[i]);
                                }
                            }
                            radiologue.radio_list_display();

                            break;
                        }
                        case 3:
                        {
                            string pat_id;
                            cout<<"Patient ID :"<<endl;
                            cin>>pat_id;

                            radiologue.clear_list();
                            for (int i=0; i<vecrad.size(); i++){
                                if(vecrad[i].get_patient_id() == pat_id){
                                    radiologue.add_radio_in_list(vecrad[i]);
                                }
                            }
                            radiologue.radio_list_display();

                            break;
                        }
                        case 4:
                        {
                            string date;
                            cout<<"Date :"<<endl;
                            cin>>date;

                            radiologue.clear_list();
                            for (int i=0; i<vecrad.size(); i++){
                                if(vecrad[i].get_date_info() == date){
                                    radiologue.add_radio_in_list(vecrad[i]);
                                }
                            }
                            radiologue.radio_list_display();

                            break;
                        }

                        case 5:
                            break;
                        default:
                            cout<<"Bad choice"<<endl;
                            break;
                        }

                    } while (display_choice!=5);

                    break;
                }

            case 2:
                {
                    //Ajout d'une radiographie -----------------------------------
                    Radiographie return_radio;
                    Patient return_patient;
                    string new_patient; //Permet d'obtenir l'info si un nouveau patient a été créé facilement au cours de la création d'une radiographie

                    tie(return_radio, return_patient, new_patient) = radiologue.add_new_radio(last_patient_id, last_radio_id, vecpat);

                    radiologue.add_radio_in_list(return_radio); //plus très utile je crois

                    //mise à jour des identifiants uniques 
                    last_patient_id = stoi(return_patient.get_id_info());
                    last_radio_id = stoi(return_radio.get_num_exam_info());


                    if(new_patient=="1"){       //mettre à jour la base de données patient et radiographie sans réécrire par dessus
                        radiologue.save_new_patient(return_patient);
                    }

                    radiologue.save_new_radio(return_radio);
                    cout<<"\n### Changes Saved ###"<<endl;

                    // Reload les bases de données à jour -> à faire dans une fonction plus propre 
                    vecpat = utilisateur.load_patient();
                    tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

                    for(int h=0; h<liste_indice.size(); h++){
                        vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
                        vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
                    }

                    int last_radio_id=-900, last_patient_id=-900;

                    for(int i=0; i<vecpat.size(); i++){
                        if (stoi(vecpat[i].get_id_info())>last_patient_id){
                            last_patient_id=stoi(vecpat[i].get_id_info());
                        }
                    }
                    for(int j=0; j<vecrad.size(); j++){
                        if (stoi(vecrad[j].get_num_exam_info())>last_radio_id){
                            last_radio_id=stoi(vecrad[j].get_num_exam_info());
                        }
                    }
                    cout<<"\n### Data reloaded ###"<<endl;
                    break;
                }
            
            case 3:
                {   //Suppression d'une radiographie -----------------------------------
                    string identifiant;
                    cout<<"Identifiant de la radiographie à supprimer :"<<endl;
                    cin>>identifiant;
                    radiologue.delete_radio(identifiant, vecrad);
                    cout<<"Radiographie supprimée avec succès !"<<endl; //faire une vérif un peu mieux quand meme 

                    //Sauvegarde radiographie dans le fichier, en écrivant par dessus  --> pour garder à jour le vecteur vecrad et la base de données sans chercher ligne par ligne dans la base de données, galère de connaitre le nombre de ligne à cause des résultats medecins et patients possibles  
                    radiologue.save_all_radio(vecrad);
                    cout<<"\n### Changes Saved ###"<<endl;

                    break;
                }

            case 4:
                {   //Modification d'une radiographie -----------------------------------
                    string identifiant;
                    Radiographie tmp; //copie la radio voulue, la modifie et la remplace dans le vecteur vecrad
                    bool trouve = false;
                    cout<<"ID de la radiographie à modifier :"<<endl;
                    cin>>identifiant;

                    for (int i=0; i<vecrad.size(); i++){
                        if(vecrad[i].get_num_exam_info()==identifiant){
                            trouve = true;
                            tmp = radiologue.modify_radio(vecrad[i]);
                            radiologue.delete_radio(identifiant, vecrad);
                            vecrad.push_back(tmp);
                            radiologue.save_all_radio(vecrad); //actualisation de la base de données, réécriture entière car même raison que dans la suppresion d'une radio
                        }
                    }
                    if (!trouve){
                        cout<<"ID inconnu"<<endl;
                    }
                    
                }

            case 5:
                //Sauvegarde des données, pas très utille car tout est sauvegardé à la fin des actions précédentes -----------------------------------
                radiologue.save_all_radio(vecrad);
                radiologue.save_all_patients(vecpat);
                cout<<"\n### Changes Saved ###"<<endl;
                break;
            
            case 6:
                {   // Reload les bases de données à jour -----------------------------------
                    vecpat = utilisateur.load_patient();
                    tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

                    for(int h=0; h<liste_indice.size(); h++){
                        vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
                        vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
                    }

                    int last_radio_id=-900, last_patient_id=-900;

                    for(int i=0; i<vecpat.size(); i++){
                        if (stoi(vecpat[i].get_id_info())>last_patient_id){
                            last_patient_id=stoi(vecpat[i].get_id_info());
                        }
                    }
                    for(int j=0; j<vecrad.size(); j++){
                        if (stoi(vecrad[j].get_num_exam_info())>last_radio_id){
                            last_radio_id=stoi(vecrad[j].get_num_exam_info());
                        }
                    }
                    cout<<"\n### Data reloaded ###"<<endl;
                    break;
                }

            case 7: 
                break;      

            default:
                cout<<"bad choice"<<endl;
                break;
            }
            
        } while (choice != 7);

    }

}