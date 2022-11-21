#include <iostream>
#include <fstream>
#include "radiographie.h"
#include "radiologue.h"
// #include "resultatPatient.h"
// #include "resultatMedecin.h"


using namespace std;

int main () {

    string id, password;

    cout<<"ID :"<<endl;
    cin>>id;
    cout<<"Password :"<<endl;
    cin>>password;

    Utilisateur utilisateur(id, password);

    pair<bool, bool> log_pair;

    log_pair = utilisateur.login();

    cout<<log_pair.first<<"\t"<<log_pair.second<<endl;


    vector<Patient> vecpat;
    vector<Radiographie> vecrad;
    vector<MedecinResult> vec_med_res;
    vector<PatientResult> vec_pat_res;
    vector<int> liste_indice;

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

    if (log_pair.first == false){
        cout<<"login error!"<<endl;
    }


    vecpat[0].patient_display();
    vecrad[0].radiographie_display();
    // if (log_pair.first == true && log_pair.second == false){
    //     //Patient
    //     Patient patient;

    //     for (int i=0; i<vecpat.size(); i++){
    //         if (vecpat[i].get_id_info() == id){
    //             patient = vecpat[i];
    //         }
    //     }
    //     cout<<"\nHello "<<patient.get_first_name_info()<<endl;

    //     patient.load_result(vecrad);
    //     patient.result_display();
    // }
  
    // if (log_pair.first == true && log_pair.second == true){
    //     //Radiologue
    //     cout<<"\nLog as a Radiologist"<<endl;
    //     cout<<"ID : "<<id<<endl;

    //     Radiologue radiologue(stoi(id));
        
    //     //Chargement des radiographies utiles au médecin concerné par la radio, à partir de la base de données complète.
        

    //     int choice;
    //     do
    //     {
    //         cout<<"\n\nChoose an action :"<<endl;
    //         cout<<"1 -\tAfficher vos radiographies"<<endl;
    //         cout<<"2 -\tAjouter une radiographie"<<endl;
    //         cout<<"3 -\tSupprimer une radiographie"<<endl;
    //         cout<<"4 -\tModifier une radiographie"<<endl;
    //         cout<<"5 -\tSauvegarder les données"<<endl;
    //         cout<<"6 -\tRecharger les données"<<endl;
    //         cout<<"7 -\tQuitter!"<<endl;

    //         cin>>choice;

    //         switch (choice)
    //         {
    //         case 1:
    //             {//accolades pour pouvoir instancier des variables dans un case de switch
    //                 int display_choice;
    //                 do
    //                 {
    //                     cout<<"\n\nMode d'affichage :"<<endl;
    //                     cout<<"1 -\tAfficher toutes vos radiographies"<<endl; //faire les filtres dans un autre switch
    //                     cout<<"2 -\tChercher par numéro d'examen"<<endl;
    //                     cout<<"3 -\tChercher par identifiant de patient"<<endl;
    //                     cout<<"4 -\tChercher par date"<<endl;
    //                     cout<<"5 -\tQuitter"<<endl;
    //                     cin>>display_choice;
    //                     switch (display_choice)
    //                     {
    //                     case 1:
    //                         radiologue.clear_list();
    //                         for (int i=0; i<vecrad.size(); i++){
    //                             if(vecrad[i].get_id_medecin_info() == id){
    //                                 radiologue.add_radio_in_list(vecrad[i]);
    //                             }
    //                         }
    //                         radiologue.radio_list_display();
                        
    //                         break;

    //                     case 2:
    //                     {
    //                         string num_exam;
    //                         cout<<"Numéro d'examen :"<<endl;
    //                         cin>>num_exam;

    //                         radiologue.clear_list();
    //                         for (int i=0; i<vecrad.size(); i++){
    //                             if(vecrad[i].get_num_exam_info() == num_exam){
    //                                 radiologue.add_radio_in_list(vecrad[i]);
    //                             }
    //                         }
    //                         radiologue.radio_list_display();

    //                         break;
    //                     }
    //                     case 3:
    //                     {
    //                         string pat_id;
    //                         cout<<"Patient ID :"<<endl;
    //                         cin>>pat_id;

    //                         radiologue.clear_list();
    //                         for (int i=0; i<vecrad.size(); i++){
    //                             if(vecrad[i].get_patient_id() == pat_id){
    //                                 radiologue.add_radio_in_list(vecrad[i]);
    //                             }
    //                         }
    //                         radiologue.radio_list_display();

    //                         break;
    //                     }
    //                     case 4:
    //                     {
    //                         string date;
    //                         cout<<"Date :"<<endl;
    //                         cin>>date;

    //                         radiologue.clear_list();
    //                         for (int i=0; i<vecrad.size(); i++){
    //                             if(vecrad[i].get_date_info() == date){
    //                                 radiologue.add_radio_in_list(vecrad[i]);
    //                             }
    //                         }
    //                         radiologue.radio_list_display();

    //                         break;
    //                     }

    //                     case 5:
    //                         break;
    //                     default:
    //                         cout<<"Bad choice"<<endl;
    //                         break;
    //                     }

    //                 } while (display_choice!=5);

    //                 break;
    //             }

    //         case 2:
    //             {
    //                 Radiographie return_radio;
    //                 Patient return_patient;
    //                 string new_patient;
    //                 tie(return_radio, return_patient, new_patient) = radiologue.add_new_radio(last_patient_id, last_radio_id, vecpat);

    //                 radiologue.add_radio_in_list(return_radio);

    //                 //mise à jour des identifiants uniques 
    //                 last_patient_id = stoi(return_patient.get_id_info());
    //                 last_radio_id = stoi(return_radio.get_num_exam_info());


    //                 if(new_patient=="1"){       //mettre à jour la base de données patient et radiographie sans réécrire par dessus
    //                     radiologue.save_new_patient(return_patient);
    //                 }

    //                 radiologue.save_new_radio(return_radio);
    //                 cout<<"\n### Changes Saved ###"<<endl;
    //                 // Reload les bases de données à jour
    //                 vecpat = utilisateur.load_patient();
    //                 tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

    //                 for(int h=0; h<liste_indice.size(); h++){
    //                     vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
    //                     vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
    //                 }

    //                 int last_radio_id=-900, last_patient_id=-900;

    //                 for(int i=0; i<vecpat.size(); i++){
    //                     if (stoi(vecpat[i].get_id_info())>last_patient_id){
    //                         last_patient_id=stoi(vecpat[i].get_id_info());
    //                     }
    //                 }
    //                 for(int j=0; j<vecrad.size(); j++){
    //                     if (stoi(vecrad[j].get_num_exam_info())>last_radio_id){
    //                         last_radio_id=stoi(vecrad[j].get_num_exam_info());
    //                     }
    //                 }
    //                 cout<<"\n### Data reloaded ###"<<endl;
    //                 break;
    //             }
            
    //         case 3:
    //             {   
    //                 string identifiant;
    //                 cout<<"Identifiant de la radiographie à supprimer :"<<endl;
    //                 cin>>identifiant;
    //                 radiologue.delete_radio(identifiant, vecrad);
    //                 cout<<"Radiographie supprimée avec succès !"<<endl;

    //                 //Sauvegarde radiographie dans le fichier, en écrivant par dessus  --> pour garder à jour le vecteur vecrad et la base de données si il y a eu une suppression de radio entre temps 
    //                 radiologue.save_all_radio(vecrad);
    //                 cout<<"\n### Changes Saved ###"<<endl;

    //                 break;
    //             }

    //         case 4:
    //             {
    //                 string identifiant;
    //                 Radiographie tmp;
    //                 bool trouve = false;
    //                 cout<<"ID de la radiographie à modifier :"<<endl;
    //                 cin>>identifiant;

    //                 for (int i=0; i<vecrad.size(); i++){
    //                     if(vecrad[i].get_num_exam_info()==identifiant){
    //                         trouve = true;
    //                         tmp = radiologue.modify_radio(vecrad[i]);
    //                         radiologue.delete_radio(identifiant, vecrad);
    //                         vecrad.push_back(tmp);
    //                         radiologue.save_all_radio(vecrad);
    //                     }
    //                 }
    //                 if (!trouve){
    //                     cout<<"ID inconnu"<<endl;
    //                 }
                    
    //             }

    //         case 5:
    //             radiologue.save_all_radio(vecrad);
    //             radiologue.save_all_patients(vecpat);
    //             cout<<"\n### Changes Saved ###"<<endl;
    //             break;
            
    //         case 6:
    //             {      // Reload les bases de données à jour
    //                 vecpat = utilisateur.load_patient();
    //                 tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

    //                 for(int h=0; h<liste_indice.size(); h++){
    //                     vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
    //                     vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
    //                 }

    //                 int last_radio_id=-900, last_patient_id=-900;

    //                 for(int i=0; i<vecpat.size(); i++){
    //                     if (stoi(vecpat[i].get_id_info())>last_patient_id){
    //                         last_patient_id=stoi(vecpat[i].get_id_info());
    //                     }
    //                 }
    //                 for(int j=0; j<vecrad.size(); j++){
    //                     if (stoi(vecrad[j].get_num_exam_info())>last_radio_id){
    //                         last_radio_id=stoi(vecrad[j].get_num_exam_info());
    //                     }
    //                 }
    //                 cout<<"\n### Data reloaded ###"<<endl;
    //                 break;
    //             }

    //         case 7: 
    //             break;      

    //         default:
    //             cout<<"bad choice"<<endl;
    //             break;
    //         }
            
    //     } while (choice != 7);

    // }


















    // //PATIENTS
    // string name = "Hunault";
    // string first_name = "César";
    // string password ="mdp bien trop faible";
    
    // Patient patient1 (name, first_name, password, "25/12/2000", "Homme");

    // Patient patient2 ("Levergeois", "Romain", "mdp", "08/09/2000", "Homme");


    // //RADIOGRAPHIES
    // Radiographie radio1 (0001, "X-ray", &patient1, "007", "15/09/2023", true);

    // Radiographie radio2 (0002, "IRM", &patient2, "009", "15/10/2023", false);

    // //CLICHES
    // Cliche img1 ("radio 1",1);
    // Cliche img2 ("radio 2",2);
    // Cliche img3 ("radio 3",3);
    // Cliche img4 ("radio 4",4);

    // //PATIENT RESULTS
    // PatientResult res_pat1(img1, "rien à signaler");
    // res_pat1.set_cliche(img2);
    // res_pat1.set_cliche(img3);

    // PatientResult res_pat2(img4, "Grosseur dans les poumons");
    // res_pat2.set_cliche(img2);
    // res_pat2.set_cliche(img3);


    // //MEDECIN RESULTS
    // MedecinResult res_med1(img1, "rien à signaler mais avec des mots scientifiques");
    // res_med1.set_cliche(img2);
    // res_med1.set_cliche(img3);
    // res_med1.set_cliche(img4);

    // //RADIOS + RAPPORTS
    // radio1.set_med_result(&res_med1);
    // radio1.set_pat_result(&res_pat1);

    // //PATIENT ACCES A SES RESULTATS
    // patient1.add_result(res_pat1);
    // patient1.add_result(res_pat2);
    
    // //patient1.result_display();


    // //RADIOLOGUE
    // Radiologue radiologue1;

    // radiologue1.add_radio_in_list(radio1);
    // radiologue1.add_radio_in_list(radio2);

    // radiologue1.radio_list_display();

    // cout<<"\n##############################1\n"<<endl;

    // tuple<Radiographie, Patient> tmp = radiologue1.add_new_radio();
    // Radiographie nouvelle_rad = get<0>(tmp);
    // Patient nouveau_pat = get<1>(tmp);

    // cout<<"\n##############################2\n"<<endl;
    // //nouvelle_rad.radiographie_display();
    
    // //nouveau_pat.patient_display();

    // //obligé de le faire à l'extérieur de new_radio(), pourquoi ??
    // radiologue1.add_radio_in_list(nouvelle_rad);
    
    // radiologue1.radio_list_display();
    
    // cout<<"\n##############################3\n"<<endl;
    
    // radiologue1.delete_radio(99);

    // cout<<"\n##############################4\n"<<endl;

    // radiologue1.radio_list_display();


}