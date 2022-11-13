#ifndef INTERFACE_MED_H
#define INTERFACE_MED_H

#include <gtkmm.h>


class FenetreRadiologue : public Gtk::Window{
    
    public:
        FenetreRadiologue();
    private:
        Gtk::HBox boiteh_container;
        Gtk::VButtonBox boiteBouton_choix_menu;
        Gtk::HBox boiteh_affichage;
        
        Gtk::Button bouton_affichage_liste_radio;
        Gtk::Button bouton_affichage_radio_simple; 
        Gtk::Button bouton_ajouter_radio;
        Gtk::Button bouton_supprimer_radio;  
        Gtk::Button bouton_reset_affichage;

        Gtk::Label espace_affichage;



};

#endif