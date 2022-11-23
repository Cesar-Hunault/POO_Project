#include <gtkmm.h>
#include "interface_login.h"
#include "application.h"
// #include "interface_med.h"

using namespace std;

int main(int argc, char* argv[]) {

    Gtk::Main app(argc, argv);

    Fenetre_login fenetre_login;
    Gtk::Main::run(fenetre_login);
    return 0;

}