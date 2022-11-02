#include <iostream>
#include "radiographie.h"
// #include "resultatPatient.h"
// #include "resultatMedecin.h"


using namespace std;

int main () {
    string name = "Hunault";
    string first_name = "César";
    string password ="test";
    
    
    //Test de la classe Patient et Radiographie
    Patient pat1 ("25/12/2000", "Homme", name, first_name, password);

    Patient pat2 ("08/09/2000", "Homme", "Levergeois", "Romain", "mdp");

    Radiographie rad1 (0001, "X-ray", &pat1, "007", "15/09/2023", true);



    Radiographie rad2 (0002, "IRM", &pat2, "009", "15/10/2023", false);

    rad2.display();

    //Test de la classe Cliche
    Cliche i1 ("radio 1",1);
    Cliche i2 ("radio 2",2);
    Cliche i3 ("radio 3",3);
    Cliche i4 ("radio 4",4);

    //i1.display();

    //Test de la classe PatientResult
    cout<<"###############################"<<endl;

    PatientResult rp1(i1, "rien à signaler");
    rp1.set_cliche(i2);
    rp1.set_cliche(i3);

    //rp1.display();

    //Test de la classe MedeinResult
    cout<<"###############################"<<endl;

    MedecinResult rm1(i1, "rien à signaler mais avec des mots scientifiques");
    rm1.set_cliche(i2);
    rm1.set_cliche(i3);
    rm1.set_cliche(i4);

   // rm1.display();



    rad1.set_med_result(&rm1);
    rad1.set_pat_result(&rp1);
    rad1.display();



}