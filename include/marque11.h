#ifndef MARQUE11_H
#define MARQUE11_H

int argc;
char **argv;

void Marque11(int argc,char **argv,char *email,char *iduser,char *nom, char * prenom);
void onDestroyMarque11(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques11( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // MARQUE11_H
