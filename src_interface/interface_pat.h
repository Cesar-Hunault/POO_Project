#ifndef INTERFACE_PAT_H
#define INTERFACE_PAT_H

#include <gtkmm.h>


class FenetrePatient : public Gtk::Window{
    
    public:
        FenetrePatient();
    private:
        Gtk::VBox boiteContainer;
        Gtk::Label message;
};

#endif