#include <gtkmm.h>
#include <string>
#include <iostream>
#include "utilisateur.h"

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    
    Gtk::Window fenetre;
    
    fenetre.set_border_width(10); //Ajouter une bordure (invisible) de 10px à la fenêtre.

    Gtk::Button bouton(Gtk::Stock::CANCEL);    
    bouton.set_can_focus(false);
    fenetre.add(bouton);
    bouton.show();
    
    Utilisateur u1("Hunault","César", "mdp");

    bouton.signal_clicked().connect(sigc::mem_fun(u1, &Utilisateur::utilisateur_display));

    Gtk::Main::run(fenetre);

    
    return 0;
}