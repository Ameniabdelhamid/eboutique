#ifndef INDEX_H
#define INDEX_H
#include <gtk/gtk.h>
int argc;
char **argv;
void onDestroy(GtkWidget *pwindow ,gpointer data);
void IndexPage1(argc,argv);
static gboolean onClick( GtkWidget *widget,GdkEventButton *event,gpointer data );
static gboolean onClickMarques( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // INDEX_H
