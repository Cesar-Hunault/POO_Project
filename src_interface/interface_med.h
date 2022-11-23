#ifndef INTERFACE_MED_H
#define INTERFACE_MED_H

#include <gtkmm.h>

class FenetreRadiologue : public Fenetre_login {
    
    public:
        FenetreRadiologue();
        void liste_radio_on_button_clicked();

    private:
        //composants de la page d'acceuil 
        Gtk::HBox boiteh_container;
        Gtk::VButtonBox boiteBouton_choix_menu;
        Gtk::HBox boiteh_affichage;
        
        Gtk::Button bouton_affichage_liste_radio;
        Gtk::Button bouton_affichage_radio_simple; 
        Gtk::Button bouton_ajouter_radio;
        Gtk::Button bouton_supprimer_radio;  
        Gtk::Button bouton_reset_affichage;

        Gtk::Label espace_affichage;

        //composants de l''affichage de la liste de radiographie
        Gtk::HBox boiteh_radio_list_container;
        Gtk::Label radio_list_label;




};

#endif