#include <gtkmm.h>
#include "interface_login.h"
#include "interface_med.h"

using namespace std;

int main(int argc, char* argv[]) {


    Gtk::Main app(argc, argv);
    FenetreRadiologue FenetreRadiologue;
    Gtk::Main::run(FenetreRadiologue);
    return 0;

}