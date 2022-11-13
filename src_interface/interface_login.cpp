#include <gtkmm.h>
#include <iostream>
#include <string>
#include "interface_login.h"
#include "utilisateur.h"

using namespace std;

Fenetre_login::Fenetre_login() : alignement(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER, 0.3, 0.3), boiteV(false, 10)
{
  set_title("Login Screen");
  set_default_size(1000,600);


  idLabel.set_text("Identifiant");
  passwordLabel.set_text("Mot de passe");

  passwordInput.set_visibility(false);

  boiteV.pack_start(idLabel);
  boiteV.pack_start(idInput);
  boiteV.pack_start(passwordLabel);
  boiteV.pack_start(passwordInput);
  boutonValider.set_label("Valider");
  boiteV.pack_start(boutonValider);


  alignement.add(boiteV);
  add(alignement);

  boutonValider.signal_clicked().connect( sigc::mem_fun(*this, &Fenetre_login::on_button_clicked) );

  show_all();
}

void Fenetre_login::on_button_clicked()
{
  string id, password;
  pair<bool, bool> log_pair;

  cout<<idInput.get_text()<<endl;
  cout<<passwordInput.get_text()<<endl;
  
  id = idInput.get_text();
  password = passwordInput.get_text();

  Utilisateur utilisateur(id, password);
  log_pair = utilisateur.login(id, password);
  
  cout<<log_pair.first<<"\t"<<log_pair.second<<endl;

  if (log_pair.first == true && log_pair.second == false){
    my_FenetrePatient.set_modal(true);//je ne sais pas a quoi ça sert
    my_FenetrePatient.show();
  }
  
  if (log_pair.first == true && log_pair.second == true){
    my_FenetreRadiologue.set_modal(true);
    my_FenetreRadiologue.show();
  }
}
