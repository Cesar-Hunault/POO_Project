#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "utilisateur.h"
#include "patient.h"
#include "radiographie.h"

using namespace std;

void Utilisateur::utilisateur_display(){
    this->get_id();
    this->get_password();
}

//return une paire de booléen permettant de connaitre la validité des identifiants de connexion et la classe de l'utilisateur : radiologue ou patient 
pair<bool, bool> Utilisateur::login(){

    ifstream file("BD_login.txt");

    string line, id_verif, password_verif, med_verif;
    bool med = false, login_state = false;
    pair<bool, bool> login;

    while (getline(file, line))
    {
        if ( line[0]!='#' && line[0]!= '\n'){
            int sep = line.find(';'); //séparateurs propres à notre base de données
            int sep2 = line.find('/');

            id_verif = line.substr(0, sep);
            password_verif = line.substr(sep+1, sep2-sep-1);
            med_verif = line.substr(sep2+1, line.length()-1);

            if (this->id == id_verif && this->password == password_verif){
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

//Charge tous les patients enregistrés dans la base de données dans un vecteur de patients
vector<Patient> Utilisateur::load_patient(){

    ifstream file2("BD_patient.txt");
    string fid, fpassword, fname, ffname, fbirth, fgen;
    vector<Patient> vecpat;

    Patient tmp;

    //Lecture de la base de données : facile car toujours 6 informations 
    while (file2 >> fid >> fpassword >> fname >> ffname >> fbirth >> fgen){
        tmp.set_id(fid);
        tmp.set_password(fpassword);
        tmp.set_name(fname);
        tmp.set_first_name(ffname);
        tmp.set_birth_date(fbirth);
        tmp.set_gender(fgen);

        vecpat.push_back(tmp);
    } 
    
    file2.close();


    return vecpat;
}

//Charge toutes les radiographies enregistrées dans la base de données dans un vecteur de radiographies
tuple<vector<Radiographie>, vector<MedecinResult>, vector<PatientResult>, vector<int>> Utilisateur::load_radiography(vector<Patient> &vecpat){

    ifstream file4("BD_radiographies.txt");

    string id_patient, line;

    vector<vector<string>> lecture;
    vector<string>lectmp;

    vector<Radiographie> vecrad;
    vector<MedecinResult> vec_med_res;
    vector<PatientResult> vec_pat_res;

    Patient *cherchepatient;
    Radiographie radtmp;
    MedecinResult med_res_tmp;
    PatientResult pat_res_tmp;

    vector<int> liste_indice;

    bool fbool;

    //Besoin de trouver le séparateur des radiographies car le nombre de ligne qui les composent est variable
    //séparateur = '}' à la fin d'une radiographie
    while(getline(file4, line)){
        lectmp.push_back(line);
        if (line[0]=='}'){
            lectmp.pop_back();  //on retire la ligne du séparateur
            lecture.push_back(lectmp);  
            lectmp.clear();
        }
    }

    for (int i=0; i<lecture.size(); i++){

        if (lecture[i].size()==6){ //si taille du vecteur = 6 alors la radiographie n'a pas encore été faite, il n'y a pas de résultats qui lui sont attribuée

            radtmp.set_num_exam(lecture[i][0]);
            radtmp.set_type(lecture[i][1]);
            id_patient = lecture[i][2];
            for(auto i = vecpat.begin(); i != vecpat.end();){   //Recherche du patient à partir de la base de données vecpat qui doit être chargée avant celle ci
                if ((*i).get_id_info()==id_patient){     //syntaxe pour obtenir accès à la méthode par l'itérateur : https://stackoverflow.com/questions/63369486/c-cant-access-a-public-attribute-in-a-class-that-is-returned-by-the-vectors
                    cherchepatient = &(*i);
                    break;
                } else {
                    i++;
                }
            }
            radtmp.set_patient(cherchepatient); //pointeur vers un patient
            radtmp.set_id_medecin(lecture[i][3]);
            radtmp.set_date(lecture[i][4]);

            if (lecture[i][5] == "1"){
                fbool = true;
            } else {
                fbool = false;
            }
            radtmp.set_state(fbool);
            
            //pas de resultats donc push back de resultats vides dans les vecteurs associés. Permet de garder la continuité de l'indice utilisé pour associer les resultats à l'extérieur de cette fonction
            vec_med_res.push_back(med_res_tmp);
            vec_pat_res.push_back(pat_res_tmp);

            vecrad.push_back(radtmp);

        } else { //state = performed donc il faut trouver le nombre de clichés associés 

            radtmp.set_num_exam(lecture[i][0]);
            radtmp.set_type(lecture[i][1]);
            id_patient = lecture[i][2];
            for(auto i = vecpat.begin(); i != vecpat.end();){
                if ((*i).get_id_info()==id_patient){
                    cherchepatient = &(*i);
                    break;
                } else {
                    i++;
                }
            }
            radtmp.set_patient(cherchepatient); //pointeur vers un patient
            radtmp.set_id_medecin(lecture[i][3]);
            radtmp.set_date(lecture[i][4]);

            if (lecture[i][5] == "1"){
                fbool = true;
            } else {
                fbool = false;
            }
            radtmp.set_state(fbool);

            //recupération du nombre de ligne qui reste pour créer les résultats. Les 6 premières lignes sont toujours les mêmes, on retrouve ensuite forcément 2 lignes de compte rrendu : un pour le patient et un pour le radiologue, et une liste de cliché, égale pour le radiologue et le patient, ce qui permet les calculs suivants : 
            int nombre_resultat = lecture[i].size()-6;
            int nombre_cliche = (nombre_resultat-2)/2;
            

            for (int j=6; j<6+nombre_cliche;){
                Cliche cliche_tmp(lecture[i][j], lecture[i][j+1]);
                j=j+2;
                med_res_tmp.set_cliche(cliche_tmp);
            }
            med_res_tmp.set_cr_medecin(lecture[i][6+nombre_cliche]);

            for (int h=6+nombre_cliche+1; h<lecture[i].size()-1;){
                
                Cliche cliche_tmp(lecture[i][h], lecture[i][h+1]);
                h=h+2;
                pat_res_tmp.set_cliche(cliche_tmp);
            }
            int n = lecture[i].size();
            pat_res_tmp.set_cr_patient(lecture[i][n-1]);

            vec_med_res.push_back(med_res_tmp);
            vec_pat_res.push_back(pat_res_tmp);

            liste_indice.push_back(i);

            // radtmp.set_med_result(&vec_med_res[i]);
            // radtmp.set_pat_result(&vec_pat_res[i]);
            //Ne marche pas ici, à faire à l'extérieur avec l'aide de la liste d'indices

            vecrad.push_back(radtmp);
        }
    }

    file4.close();

    return make_tuple(vecrad, vec_med_res, vec_pat_res, liste_indice);
}

