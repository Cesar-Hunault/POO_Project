#include <iostream>
#include <fstream>
#include <vector>
#include "radiographie.h"
#include "radiologue.h"
// #include "resultatPatient.h"
// #include "resultatMedecin.h"

using namespace std;

int main () {

    //PATIENTS
    // string result, result2; 
    // Patient patient1 ("1", "mdp", "Porcheron", "Lise", "06/08/1999", "Femme");

    // Patient patient2 ("2", "mdp", "Cornuault", "Anna", "05/02/2000", "Femme");

    // // result = patient1.patient_display();
    // // result2 = patient2.patient_display();

    // // cout<<result<<endl;
    // // cout<<result2<<endl;

    // // //Sauvegarde patient dans le fichier
    // // ofstream file1("BD_patient.txt");
    // // file1 << patient1.get_id() <<'\n' << patient1.get_password() << '\n' << patient1.get_name() << '\n' << patient1.get_first_name() << '\n' << patient1.get_birth_date() << '\n' << patient1.get_gender()<< '\n';
    // // file1 << patient2.get_id() <<'\n' << patient2.get_password() << '\n' << patient2.get_name() << '\n' << patient2.get_first_name() << '\n' << patient2.get_birth_date() << '\n' << patient2.get_gender()<< '\n';
    // // file1.close();

    // //Chargement de la base de données de patients
    // ifstream file2("BD_patient.txt");
    // string fid, fpassword, fname, ffname, fbirth, fgen;
    // vector<Patient> vecpat;
    // Patient tmp("0", "0", "0", "0", "0", "0");


    // while (file2 >> fid >> fpassword >> fname >> ffname >> fbirth >> fgen){
    //     tmp.set_id(fid);
    //     tmp.set_password(fpassword);
    //     tmp.set_name(fname);
    //     tmp.set_first_name(ffname);
    //     tmp.set_birth_date(fbirth);
    //     tmp.set_gender(fgen);

    //     vecpat.push_back(tmp);
    // } 
    
    // file2.close();
    // // string result_tmp;

    // // for (int i = 0; i < vecpat.size(); ++i) {
    // //     result_tmp = vecpat[i].patient_display();
    // //     cout<< "\n##################result tmp \n"<<result_tmp<<endl;
    // // }
    

    // //Sauvegarde radiographie dans le fichier
    // ofstream file3("BD_radiographies.txt");

    // vector<Radiographie> list_radio;
    // list_radio.push_back(radio1);
    // list_radio.push_back(radio2);
    // string result_radio;

    // for (int i=0; i<list_radio.size(); i++){
    //     // file3<< "{\n";
    //     file3 << list_radio[i].get_num_exam() <<'\n'<< list_radio[i].get_type() <<'\n'<< list_radio[i].get_patient_id() <<'\n'<< list_radio[i].get_id_medecin() <<'\n'<< list_radio[i].get_date() <<'\n'<< list_radio[i].get_state();
    //     if (list_radio[i].get_state()){
    //         file3<< list_radio[i].get_med_result_info() <<'\n'<< list_radio[i].get_pat_result_info()<<'\n';
    //     } else {
    //         file3<<'\n';
    //     }
    //     file3<< "}\n";
    // }

    // file3.close();


    // Chargement de la base de données de radiographies
    // ifstream file4("BD_radiographies.txt");

    // vector<vector<string>> lecture;
    // vector<string>lectmp;
    // string fnum_exam, ftype, fpat_id, fmed_id, fdate, fstate, resulttmp, s1, s2, line;
    // vector<Radiographie> vecrad;
    // Patient *cherchepatient;
    // Radiographie radtmp;

    // vector<MedecinResult> vec_med_res;
    // vector<PatientResult> vec_pat_res;

    // bool fbool;

    // LECTURE DE LA BASE DE DONNÉES RADIOGRAPHIE
    // while(getline(file4, line)){
    //     lectmp.push_back(line);
    //     if (line[0]=='}'){
    //         lectmp.pop_back();
    //         lecture.push_back(lectmp);
    //         lectmp.clear();
    //     }
    // }

    // for (int i=0; i<lecture.size(); i++){
        
    //     MedecinResult med_res_tmp;
    //     PatientResult pat_res_tmp;

    //     if (lecture[i].size()==6){

    //         radtmp.set_num_exam(lecture[i][0]);
    //         radtmp.set_type(lecture[i][1]);
    //         s2 = lecture[i][2];
    //         for(auto i = vecpat.begin(); i != vecpat.end();){
    //             if ((*i).get_id()==s2){
    //                 cherchepatient = &(*i);
    //                 break;
    //             } else {
    //                 i++;
    //             }
    //         }
    //         radtmp.set_patient(cherchepatient); //pointeur vers un patient
    //         radtmp.set_id_medecin(lecture[i][3]);
    //         radtmp.set_date(lecture[i][4]);

    //         if (lecture[i][5] == "1"){
    //             fbool = true;
    //         } else {
    //             fbool = false;
    //         }
    //         radtmp.set_state(fbool);

    //         vecrad.push_back(radtmp);

    //         vec_med_res.push_back(med_res_tmp);
    //         vec_pat_res.push_back(pat_res_tmp);

    //     } else {

    //         radtmp.set_num_exam(lecture[i][0]);
    //         radtmp.set_type(lecture[i][1]);
    //         s2 = lecture[i][2];
    //         for(auto i = vecpat.begin(); i != vecpat.end();){
    //             if ((*i).get_id()==s2){
    //                 cherchepatient = &(*i);
    //                 break;
    //             } else {
    //                 i++;
    //             }
    //         }
    //         radtmp.set_patient(cherchepatient); //pointeur vers un patient
    //         radtmp.set_id_medecin(lecture[i][3]);
    //         radtmp.set_date(lecture[i][4]);

    //         if (lecture[i][5] == "1"){
    //             fbool = true;
    //         } else {
    //             fbool = false;
    //         }
    //         radtmp.set_state(fbool);

    //         recupération du nombre de ligne qui reste pour créer les résultats
    //         int nombre_resultat = lecture[i].size()-6;
    //         int nombre_cliche = (nombre_resultat-2)/2;
            

    //         for (int j=6; j<6+nombre_cliche;){
    //             Cliche cliche_tmp(lecture[i][j], lecture[i][j+1]);
    //             j=j+2;
    //             med_res_tmp.set_cliche(cliche_tmp);
    //         }
    //         med_res_tmp.set_cr_medecin(lecture[i][6+nombre_cliche]);

    //         for (int h=6+nombre_cliche+1; h<lecture[i].size()-1;){
                
    //             Cliche cliche_tmp(lecture[i][h], lecture[i][h+1]);
    //             h=h+2;
    //             pat_res_tmp.set_cliche(cliche_tmp);
    //         }
    //         int n = lecture[i].size();
    //         pat_res_tmp.set_cr_patient(lecture[i][n-1]);

    //         vec_med_res.push_back(med_res_tmp);
    //         vec_pat_res.push_back(pat_res_tmp);

    //         radtmp.set_med_result(&vec_med_res[i]);
    //         radtmp.set_pat_result(&vec_pat_res[i]);

            
            
    //         vecrad.push_back(radtmp);
    //     }
    // }

    // file4.close();
    
    // string result_vec_tmp;
    // for (int i=0; i<vec_pat_res.size(); i++){
    //     result_vec_tmp = vec_pat_res[i].patient_result_display();
    //     cout<<"################"<<i+1<<"################"<<endl;
    //     cout<<result_vec_tmp<<endl;
    // }

    // for (int i=0; i<vecrad.size(); i++){
    //     resulttmp = vecrad[i].radiographie_display();
    //     cout<<"################"<<i+1<<"################"<<endl;
    //     cout<<resulttmp<<endl;
    // }

    



    Utilisateur utilisateur("1", "123");

    pair<bool, bool> log_pair;
    log_pair = utilisateur.login("1", "123");

    cout<<log_pair.first <<"\t"<< log_pair.second<<endl;

    vector<Patient> vecpat;
    vector<Radiographie> vecrad;
    vector<MedecinResult> vec_med_res;
    vector<PatientResult> vec_pat_res;
    vector<int> liste_indice;

    string test, test2, test3, test4;
    vecpat = utilisateur.load_patient();
    tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

    // for(int i=0; i<vecpat.size(); i++){
    //     test = vecpat[i].patient_display();
    //     cout<<test<<endl;
    // }

    for(int h=0; h<liste_indice.size(); h++){
        vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
        vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
    }
    
    for(int j=0; j<vecrad.size(); j++){
        test4 = vecrad[j].radiographie_display();
        cout<<test4<<endl;
    }
    // cout<<"#######################"<<endl;
    // cout<<vecrad.size()<<endl;


    // for(int i=0; i<vec_med_res.size(); i++){
    //     test2 = vec_med_res[i].medecin_result_display();
    //     cout<<test2<<endl;
    // }

    // for(int i=0; i<vec_pat_res.size(); i++){
    //     test3 = vec_pat_res[i].patient_result_display();
    //     cout<<test3<<endl;
    // }




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