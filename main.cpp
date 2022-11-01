#include <iostream>
#include "radiographie.h"


using namespace std;

int main () {
    string name = "Hunault";
    string first_name = "César";
    string password ="test";
    
    Patient pat1 ("25/12/2000", "Homme", name, first_name, password);

    Patient pat2 ("08/09/2000", "Homme", "Levergeois", "Romain", "mdp");

    Radiographie rad1 (0001, "X-ray", &pat1, "007", "15/09/2023", true);
   
    rad1.display();

    Radiographie rad2 (0002, "IRM", &pat2, "009", "15/10/2023", false);

    cout<<"###############################"<<endl;
    rad2.display();
}