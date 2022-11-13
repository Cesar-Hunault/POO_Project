#include <gtkmm.h>
#include "interface_med.h"

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

    boiteh_container.pack_start(boiteh_affichage);
    boiteh_container.pack_start(boiteBouton_choix_menu, Gtk::PACK_SHRINK);

    add(boiteh_container);

  show_all_children();
}