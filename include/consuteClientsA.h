#ifndef CONSUTECLIENTSA_H
#define CONSUTECLIENTSA_H



int argc;
char **argv;
char *email;
void onDestroyConCA(GtkWidget *pwindow ,gpointer data);
void consuteClientsA(int argc,char **argv);
static gboolean onClickConCA( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // CONSUTECLIENTSA_H
