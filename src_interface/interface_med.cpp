#include <gtkmm.h>
#include <vector>
#include "interface_med.h"
#include "radiographie.h"
#include "patient.h"
#include "interface_login.h"

FenetreRadiologue::FenetreRadiologue(): boiteh_container(false, 10), boiteBouton_choix_menu(Gtk::BUTTONBOX_CENTER, 10)
{
  set_title("Radiologue Screen");
  set_default_size(1000,600);
  set_border_width(20);

  bouton_affichage_liste_radio.set_label("Affichage Liste Radio");
  bouton_affichage_radio_simple.set_label("Afficher une Radio");
  bouton_ajouter_radio.set_label("Ajouter une Radio");
  bouton_supprimer_radio.set_label("Supprimer une Radio");
  bouton_reset_affichage.set_label("Reinitialiser l'affichage");

  espace_affichage.set_text("Espace d'affichage");

  boiteBouton_choix_menu.pack_start(bouton_affichage_liste_radio);
  boiteBouton_choix_menu.pack_start(bouton_affichage_radio_simple);
  boiteBouton_choix_menu.pack_start(bouton_ajouter_radio);
  boiteBouton_choix_menu.pack_start(bouton_supprimer_radio);
  boiteBouton_choix_menu.pack_start(bouton_reset_affichage);

  boiteh_affichage.pack_start(espace_affichage);

  radio_list_label.set_text("Test modification");
  boiteh_radio_list_container.pack_start(radio_list_label);
  boiteh_affichage.pack_start(boiteh_radio_list_container);
  

  boiteh_container.pack_start(boiteh_affichage);


  boiteh_container.pack_start(boiteBouton_choix_menu, Gtk::PACK_SHRINK);

  add(boiteh_container);

  bouton_affichage_liste_radio.signal_clicked().connect( sigc::mem_fun(*this, &FenetreRadiologue::liste_radio_on_button_clicked) );

  show_all_children();
  
  boiteh_radio_list_container.hide();
}

void FenetreRadiologue::liste_radio_on_button_clicked(){

  espace_affichage.hide();
  Fenetre_login fenetre_login;

  radio_list_label.set_text(fenetre_login.get_vecpat_indice(0).patient_display());
  

  boiteh_radio_list_container.show();

}