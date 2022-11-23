#ifndef INTERFACE_LOGIN_H
#define INTERFACE_LOGIN_H

#include <gtkmm.h>
#include <vector>
#include "patient.h"
#include "radiographie.h"
#include "radiologue.h"
#include "interface_pat.h"

class Radiologue;

class Fenetre_login : public Gtk::Window{
    public:
        Fenetre_login();
        void login_on_button_clicked();

        Patient get_vecpat_indice(int i){
            return this->vecpat[i];
        }

        void affichage_radio_on_button_clicked();

        void affichage_radio_liste_complete_on_button_clicked();
        void validation_affichage_radio_num_exam();
        void affichage_radio_num_exam_on_button_clicked();
        
        void affichage_radio_id_patient_on_button_clicked();
        void validation_affichage_radio_id_pat();
        
        void affichage_radio_date_on_button_clicked();
        void validation_affichage_radio_date();

        void affichage_quitter_on_button_clicked();

    private:

        Gtk::HBox Main_container;

        Radiologue radiologue;

        // Login screen --------------------------------------- 
        Gtk::VBox boite_login;
        Gtk::Entry idInput;
        Gtk::Label idLabel;
        Gtk::Entry passwordInput;
        Gtk::Label passwordLabel;
        Gtk::Button boutonValider;
        Gtk::Alignment alignement;   
    
        // Doctor screen ---------------------------------------
            //composants de la page d'acceuil 
        Gtk::HBox boiteh_container;
        Gtk::VButtonBox boiteBouton_choix_menu;
        Gtk::HBox boiteh_affichage;
        
        Gtk::Button bouton_affichage_liste_radio;
        Gtk::Button bouton_ajouter_radio;
        Gtk::Button bouton_supprimer_radio;  
        Gtk::Button bouton_modifer_radio; 
        Gtk::Button bouton_sauvegarder;
        Gtk::Button bouton_charger;

        Gtk::Label espace_affichage;

            //Affichage des radios
        Gtk::HBox boiteh_affichage_radio;
        Gtk::ScrolledWindow scroll_view;

        Gtk::VButtonBox boiteBouton_choix_affichage_radio;
        Gtk::Button affichage_liste;
        Gtk::Button affichage_num_exam;
        Gtk::Button affichage_id_patient; 
        Gtk::Button affichage_date; 
        Gtk::Button affichage_quitter; 

        Gtk::Label label_affichage_radio;

        Gtk::VBox formulaire_validation;

        Gtk::VBox formulaire_validation_num_exam;
        Gtk::Entry entry_user_input_affichage_num_exam;
        Gtk::Label label_user_input_affichage_num_exam;
        Gtk::Button valider_selection_num_exam; 

        Gtk::VBox formulaire_validation_id_pat;
        Gtk::Entry entry_user_input_affichage_id_pat;
        Gtk::Label label_user_input_affichage_id_pat;
        Gtk::Button valider_selection_id_pat; 

        Gtk::VBox formulaire_validation_date;
        Gtk::Entry entry_user_input_affichage_date;
        Gtk::Label label_user_input_affichage_date;
        Gtk::Button valider_selection_date; 


    protected:
        // FenetreRadiologue my_FenetreRadiologue;
        FenetrePatient my_FenetrePatient; 
        vector<Patient> vecpat;
        vector<Radiographie> vecrad;
        vector<MedecinResult> vec_med_res;
        vector<PatientResult> vec_pat_res;
        vector<int> liste_indice;


};

#endif