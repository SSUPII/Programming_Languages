#include "lib.h"
#include <gtk/gtk.h>

//Window initialization.
window::window() {
    int *argc; char ***argv;

    GtkWidget *window;
    gtk_init(argc, argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    gtk_main();

}


