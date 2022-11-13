#ifndef INTERFACE_LOGIN_H
#define INTERFACE_LOGIN_H

#include <gtkmm.h>
#include "interface_med.h"
#include "interface_pat.h"

class Fenetre_login : public Gtk::Window{
    public:
        Fenetre_login();
        void on_button_clicked();

    private:
        Gtk::VBox boiteV;
        Gtk::Entry idInput;
        Gtk::Label idLabel;
        Gtk::Entry passwordInput;
        Gtk::Label passwordLabel;
        Gtk::Button boutonValider;
        Gtk::Alignment alignement;   
    
    protected:
        FenetreRadiologue my_FenetreRadiologue; 
        FenetrePatient my_FenetrePatient; 


};

#endif