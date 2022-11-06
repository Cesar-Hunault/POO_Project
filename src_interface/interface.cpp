#include <gtkmm.h>
#include <string>
#include <iostream>
#include "utilisateur.h"
#include "radiographie.h"
#include "radiologue.h"

int main(int argc, char* argv[]) {
    
    //PATIENTS
    Patient patient1 ("Hunault", "César", "mdp", "25/12/2000", "Homme");
    Patient patient2 ("Levergeois", "Romain", "mdp", "08/09/2000", "Homme");
    
    //RADIOGRAPHIES
    Radiographie radio1 (0001, "X-ray", &patient1, "007", "15/09/2023", true);
    Radiographie radio2 (0002, "IRM", &patient2, "009", "15/10/2023", false);

    //CLICHES
    Cliche img1 ("radio 1",1);
    Cliche img2 ("radio 2",2);
    Cliche img3 ("radio 3",3);
    Cliche img4 ("radio 4",4);

    //PATIENT RESULTS
    PatientResult res_pat1(img1, "rien à signaler");
    res_pat1.set_cliche(img2);
    res_pat1.set_cliche(img3);

    PatientResult res_pat2(img4, "Grosseur dans les poumons");
    res_pat2.set_cliche(img2);
    res_pat2.set_cliche(img3);
    
    //MEDECIN RESULTS
    MedecinResult res_med1(img1, "rien à signaler mais avec des mots scientifiques");
    res_med1.set_cliche(img2);
    res_med1.set_cliche(img3);
    res_med1.set_cliche(img4);

    //RADIOS + RAPPORTS
    radio1.set_med_result(&res_med1);
    radio1.set_pat_result(&res_pat1);

    //PATIENT ACCES A SES RESULTATS
    patient1.add_result(res_pat1);
    patient1.add_result(res_pat2);
    
    //RADIOLOGUE
    Radiologue radiologue1;
    radiologue1.add_radio_in_list(radio1);
    radiologue1.add_radio_in_list(radio2);
    
    
    
    Gtk::Main app(argc, argv);
    
    Gtk::Window fenetre;
    
    
    fenetre.set_border_width(10); //Ajouter une bordure (invisible) de 10px à la fenêtre.
    fenetre.set_default_size(1000,600);

    Gtk::HBox boiteh_container(false, 10);
    Gtk::VButtonBox boiteBouton_choix_menu(Gtk::BUTTONBOX_CENTER, 10);
    Gtk::HBox boiteh_affichage;

    Gtk::Button bouton("Affichage radio 1");   
    Gtk::Button bouton_reset("Reset");    

    bouton.set_can_focus(false);
    bouton_reset.set_can_focus(false);

    // fenetre.add(bouton);
    // bouton.show();
    

    // bouton.signal_clicked().connect(sigc::mem_fun(u1, &Utilisateur::utilisateur_display));

    Gtk::Label etiquette("Espace d'affichage");

    bouton.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(etiquette, &Gtk::Label::set_text), radio1.radiographie_display()));
    bouton_reset.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(etiquette, &Gtk::Label::set_text), "Espace d'affichage"));


    // fenetre.add(etiquette);
    // etiquette.show();

    boiteBouton_choix_menu.pack_start(bouton);
    boiteBouton_choix_menu.pack_start(bouton_reset);

    boiteh_affichage.pack_start(etiquette);

    boiteh_container.pack_start(boiteh_affichage);
    boiteh_container.pack_start(boiteBouton_choix_menu, Gtk::PACK_SHRINK);


    fenetre.add(boiteh_container); 
    
    fenetre.show_all();

    Gtk::Main::run(fenetre);

    
    return 0;
}