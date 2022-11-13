#include <gtkmm.h>
#include "interface_pat.h"

FenetrePatient::FenetrePatient(){
  set_title("Patient Screen");
  set_default_size(1000,600);

  message.set_text("Affichage Patient");

  boiteContainer.add(message);
  add(boiteContainer);

  show_all_children();
}