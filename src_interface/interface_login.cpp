#include <gtkmm.h>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "interface_login.h"
#include "interface_med.h"
#include "utilisateur.h"
#include "patient.h"
#include "radiographie.h"
#include "radiologue.h"

using namespace std;

Fenetre_login::Fenetre_login() : alignement(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER, 0.3, 0.3), boite_login(false, 10), boiteh_container(false, 10), boiteBouton_choix_menu(Gtk::BUTTONBOX_CENTER, 10), boiteBouton_choix_affichage_radio(Gtk::BUTTONBOX_CENTER, 10), boiteh_affichage(Gtk::PACK_EXPAND_WIDGET)
{
  set_title("Login Screen");
  set_default_size(1000,600);

  // Login screen ---------------------------------------------------------------------------------
  idLabel.set_text("Identifiant");
  passwordLabel.set_text("Mot de passe");

  passwordInput.set_visibility(false);

  boite_login.pack_start(idLabel);
  boite_login.pack_start(idInput);
  boite_login.pack_start(passwordLabel);
  boite_login.pack_start(passwordInput);
  boutonValider.set_label("Valider");
  boite_login.pack_start(boutonValider);

  boutonValider.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::login_on_button_clicked) );


  // Doctor screen --------------------------------------------------------------------------------
    //composants de la page d'acceuil 
  bouton_affichage_liste_radio.set_label("Afficher vos radiographies");
  bouton_ajouter_radio.set_label("Ajouter une radiographie");
  bouton_supprimer_radio.set_label("Supprimer une radiographie");
  bouton_modifer_radio.set_label("Modifier une radiographie");
  bouton_sauvegarder.set_label("Sauvegarder les données");
  bouton_charger.set_label("Recharger les données");

  espace_affichage.set_text("Choisissez une action");

  boiteBouton_choix_menu.pack_start(bouton_affichage_liste_radio);
  boiteBouton_choix_menu.pack_start(bouton_ajouter_radio);
  boiteBouton_choix_menu.pack_start(bouton_supprimer_radio);
  boiteBouton_choix_menu.pack_start(bouton_modifer_radio);
  boiteBouton_choix_menu.pack_start(bouton_sauvegarder);
  boiteBouton_choix_menu.pack_start(bouton_charger);


  boiteh_affichage.pack_start(espace_affichage);

  

  boiteh_container.pack_start(boiteh_affichage);


  boiteh_container.pack_start(boiteBouton_choix_menu, Gtk::PACK_SHRINK);

    //Affichage des radios

  affichage_liste.set_label("Afficher toutes vos radiographies");
  affichage_num_exam.set_label("Chercher par numéro d'examen");
  affichage_id_patient.set_label("Chercher par identifiant de patient");
  affichage_date.set_label("Chercher par date");
  affichage_quitter.set_label("Quitter");

  label_affichage_radio.set_text("Choissiez une option d'affichage");

  boiteBouton_choix_affichage_radio.pack_start(affichage_liste);
  boiteBouton_choix_affichage_radio.pack_start(affichage_num_exam);
  boiteBouton_choix_affichage_radio.pack_start(affichage_id_patient);
  boiteBouton_choix_affichage_radio.pack_start(affichage_date);
  boiteBouton_choix_affichage_radio.pack_start(affichage_quitter);

      //par num exam
  valider_selection_num_exam.set_label("Valider");
  formulaire_validation_num_exam.pack_start(label_user_input_affichage_num_exam);
  formulaire_validation_num_exam.pack_start(entry_user_input_affichage_num_exam);
  formulaire_validation_num_exam.pack_start(valider_selection_num_exam);

      //par id patient
  valider_selection_id_pat.set_label("Valider");
  formulaire_validation_id_pat.pack_start(label_user_input_affichage_id_pat);
  formulaire_validation_id_pat.pack_start(entry_user_input_affichage_id_pat);
  formulaire_validation_id_pat.pack_start(valider_selection_id_pat);

      //par date
  valider_selection_date.set_label("Valider");
  formulaire_validation_date.pack_start(label_user_input_affichage_date);
  formulaire_validation_date.pack_start(entry_user_input_affichage_date);
  formulaire_validation_date.pack_start(valider_selection_date);

  formulaire_validation.pack_start(formulaire_validation_num_exam);
  formulaire_validation.pack_start(formulaire_validation_id_pat);
  formulaire_validation.pack_start(formulaire_validation_date);

  boiteh_affichage_radio.pack_start(formulaire_validation);

  scroll_view.add(label_affichage_radio);
  boiteh_affichage_radio.pack_start(scroll_view);

  boiteh_affichage.pack_start(boiteh_affichage_radio);
  boiteh_affichage.pack_start(boiteBouton_choix_affichage_radio);




  //affiche les choix d'affichages possibles
  bouton_affichage_liste_radio.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_radio_on_button_clicked) );

  //affiche la liste entiere des radiographies du radiologue
  affichage_liste.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_radio_liste_complete_on_button_clicked) );

  //Affiche le formulaire de choix du num d'examen et la radio trouvée
  affichage_num_exam.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_radio_num_exam_on_button_clicked) );
  valider_selection_num_exam.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::validation_affichage_radio_num_exam) );

  //Affiche le formulaire de choix de l'id patient et les radios trouvées
  affichage_id_patient.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_radio_id_patient_on_button_clicked) );
  valider_selection_id_pat.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::validation_affichage_radio_id_pat) );

  //Affiche le formulaire de choix de la date et les radios trouvées
  affichage_date.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_radio_date_on_button_clicked) );
  valider_selection_date.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::validation_affichage_radio_date) );
  
  //Quitter l'affichage
  affichage_quitter.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::affichage_quitter_on_button_clicked) );



  // Ajout des boites dans Main Container ---------------------------------------------------------

  alignement.add(boite_login);
  Main_container.add(alignement);
  Main_container.add(boiteh_container);

  add(Main_container);




  

  show_all();
  
  boiteh_container.hide();
  
}

void Fenetre_login::login_on_button_clicked()
{
  string id, password, test4;
  pair<bool, bool> log_pair;

  cout<<idInput.get_text()<<endl;
  cout<<passwordInput.get_text()<<endl;
  
  id = idInput.get_text();
  password = passwordInput.get_text();

  Utilisateur utilisateur(id, password);
  log_pair = utilisateur.login();

  
  vecpat = utilisateur.load_patient();
  tie(vecrad, vec_med_res, vec_pat_res, liste_indice) = utilisateur.load_radiography(vecpat);

  for(int h=0; h<liste_indice.size(); h++){
    vecrad[liste_indice[h]].set_med_result(&vec_med_res[liste_indice[h]]);
    vecrad[liste_indice[h]].set_pat_result(&vec_pat_res[liste_indice[h]]);
  }
  
  cout<<log_pair.first<<"\t"<<log_pair.second<<endl;


  if (log_pair.first == true && log_pair.second == false){
    set_title("Patient Screen");
    show_all();
    boite_login.hide();
  }
  
  if (log_pair.first == true && log_pair.second == true){
    set_title("Doctor Screen");
    show_all();
    boite_login.hide();
    boiteh_affichage_radio.hide();
    boiteBouton_choix_affichage_radio.hide();
    formulaire_validation.hide();

    radiologue.set_id_medecin(id);
    radiologue.set_password_medecin(password);

  }
}


void Fenetre_login::affichage_radio_on_button_clicked(){

  espace_affichage.hide();
  boiteBouton_choix_menu.hide();

    boiteBouton_choix_affichage_radio.show();
    boiteh_affichage_radio.show();

}

void Fenetre_login::affichage_radio_liste_complete_on_button_clicked(){
  scroll_view.show();
  formulaire_validation.hide();

  radiologue.clear_list(); //Nettoyage de la liste de radio dépendamment du filtre voulu, répété à chaque choix

  for (int i=0; i<vecrad.size(); i++){
      if(vecrad[i].get_id_medecin_info() == radiologue.get_id_medecin_info()){
          radiologue.add_radio_in_list(vecrad[i]);
      }
  }

  label_affichage_radio.set_text(radiologue.radio_list_display());
}


void Fenetre_login::affichage_radio_num_exam_on_button_clicked(){
  
  label_user_input_affichage_num_exam.set_text("Numéro d'examen :");
  formulaire_validation.hide();
  scroll_view.hide();
  formulaire_validation.show();
  formulaire_validation_id_pat.hide();
  formulaire_validation_date.hide();


}
void Fenetre_login::validation_affichage_radio_num_exam(){

  string user_input;

  user_input = entry_user_input_affichage_num_exam.get_text();

  scroll_view.show();
  formulaire_validation_num_exam.hide();

  radiologue.clear_list();
  for (int i=0; i<vecrad.size(); i++){
      if(vecrad[i].get_num_exam_info() == user_input){
          radiologue.add_radio_in_list(vecrad[i]);
      }
  }
  label_affichage_radio.set_text(radiologue.radio_list_display());
}


void Fenetre_login::affichage_radio_id_patient_on_button_clicked(){
  label_user_input_affichage_id_pat.set_text("Identifiant du patient :");
  formulaire_validation.hide();
  scroll_view.hide();
  formulaire_validation.show();
  formulaire_validation_num_exam.hide();
  formulaire_validation_date.hide();

  
}
void Fenetre_login::validation_affichage_radio_id_pat(){

  string user_input;

  user_input = entry_user_input_affichage_id_pat.get_text();

  scroll_view.show();
  formulaire_validation_id_pat.hide();

  radiologue.clear_list();
  for (int i=0; i<vecrad.size(); i++){
      if(vecrad[i].get_patient_id() == user_input){
          radiologue.add_radio_in_list(vecrad[i]);
      }
  }

  label_affichage_radio.set_text(radiologue.radio_list_display());

}


void Fenetre_login::affichage_radio_date_on_button_clicked(){
  label_user_input_affichage_date.set_text("Date :");
  formulaire_validation.hide();
  scroll_view.hide();
  formulaire_validation.show();
  formulaire_validation_num_exam.hide();
  formulaire_validation_id_pat.hide();

  
}
void Fenetre_login::validation_affichage_radio_date(){

  string user_input;

  user_input = entry_user_input_affichage_date.get_text();

  scroll_view.show();
  formulaire_validation_date.hide();

  radiologue.clear_list();
  for (int i=0; i<vecrad.size(); i++){
      if(vecrad[i].get_date_info() == user_input){
          radiologue.add_radio_in_list(vecrad[i]);
      }
  }

  label_affichage_radio.set_text(radiologue.radio_list_display());

}


void Fenetre_login::affichage_quitter_on_button_clicked(){

  espace_affichage.show();
  boiteBouton_choix_menu.show();

  boiteBouton_choix_affichage_radio.hide();
  boiteh_affichage_radio.hide();
}


