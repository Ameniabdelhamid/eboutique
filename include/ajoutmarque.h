#ifndef AJOUTMARQUE_H
#define AJOUTMARQUE_H
int argc;
char **argv;
char *email;
void onDestroyMar(GtkWidget *pwindow ,gpointer data);
void AjoutMarque(int argc,char **argv);
static gboolean onClickMar( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // AJOUTMARQUE_H
