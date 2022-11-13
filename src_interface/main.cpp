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
    string result, result2; 
    Patient patient1 ("1", "mdp", "Porcheron", "Lise", "25/12/2000", "Femme");

    Patient patient2 ("2", "mdp", "Cornuault", "Anna", "08/09/2000", "Femme");

    result = patient1.patient_display();
    result2 = patient2.patient_display();

    cout<<result<<endl;
    cout<<result2<<endl;


    ofstream file1("BD_patient.txt");
    file1 << patient1.get_id() <<'\n' << patient1.get_password() << '\n' << patient1.get_name() << '\n' << patient1.get_first_name() << '\n' << patient1.get_birth_date() << '\n' << patient1.get_gender()<< '\n';
    file1 << patient2.get_id() <<'\n' << patient2.get_password() << '\n' << patient2.get_name() << '\n' << patient2.get_first_name() << '\n' << patient2.get_birth_date() << '\n' << patient2.get_gender()<< '\n';
    file1.close();

    ifstream file2("BD_patient.txt");
    string fid, fpassword, fname, ffname, fbirth, fgen;
    vector<Patient> vecpat;
    Patient tmp("0", "0", "0", "0", "0", "0");


    while (file2 >> fid >> fpassword >> fname >> ffname >> fbirth >> fgen){
        tmp.set_id(fid);
        tmp.set_password(fpassword);
        tmp.set_name(fname);
        tmp.set_first_name(ffname);
        tmp.set_birth_date(fbirth);
        tmp.set_gender(fgen);

        vecpat.push_back(tmp);
    } 

    string result_tmp;

    for (int i = 0; i < vecpat.size(); ++i) {
        result_tmp = vecpat[i].patient_display();
        cout<< "\n##################result tmp \n"<<result_tmp<<endl;
    }
    

    string res;
    res = tmp.patient_display();
    cout<< "\n################## result tmp sans boucle \n"<<res<<endl;
    
    file2.close();
















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